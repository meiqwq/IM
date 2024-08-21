#include "datadb.h"
#include <QMessageBox>
#include <QSqlQuery>
#include <QVariant>
#include <QtDebug>

#include <QObject>
#include "Utilities/utilities.h"

//静态成员变量的类外初始化
DataDB* DataDB::db = NULL;
DataDB::DataDB() {
	sqldb = QSqlDatabase::addDatabase("QSQLITE");
    sqldb.setDatabaseName("User.db");
	if (!sqldb.open()) {
        QMessageBox::warning(NULL, "错误", "打开数据库时出现错误!", QMessageBox::Yes);
	}

	//下列是初始化建表
	QSqlQuery query;
	query.exec("CREATE TABLE UserInfo ("
		"Id INTEGER PRIMARY KEY, "
		"Username VARCHAR(40) NOT NULL, "
        "Pwd VARCHAR(40) NOT NULL, "
        "Avatar VARCHAR(512) )");
	//好友关系表，单向好友
	query.exec("CREATE TABLE Friendship ("
		"MyId INTEGER, "
		"FriendId INTEGER, "
		"FOREIGN KEY (MyId) REFERENCES UserInfo(Id),"
		"FOREIGN KEY (FriendId) REFERENCES UserInfo(Id))");
	//离线消息列表
	query.exec("CREATE TABLE OfflineMsg ("
		"Sender INTEGER, "
		"Reciever INTEGER, "
		"Msg VARCHAR(512),"
		"DT datetime NOT NULL,"
		"FOREIGN KEY (Sender) REFERENCES UserInfo(Id),"
		"FOREIGN KEY (Reciever) REFERENCES UserInfo(Id))");
	query.exec("CREATE TABLE Msg ("
		"Sender INTEGER,"
		"Reciever INTEGER,"
		"Msg VARCHAR(512),"
		"DT datetime NOT NULL,"
		"FOREIGN KEY (Sender) REFERENCES UserInfo(Id),"
		"FOREIGN KEY (Reciever) REFERENCES UserInfo(Id))");
	//建表完成

}
DataDB::~DataDB() {
	if (db != NULL) {
		delete db;
	}
}
DataDB* DataDB::GetInstance() {
	if (db == NULL) {
		db = new DataDB;
	}
	return db;
}
//查询所有好友的信息，返回一个包含User Info的QList
QList<UserInfo> DataDB::selectAllFriendsUserInfo(quint32 UserId) {
	QSqlQuery query;
	query.prepare("select Id,Username from UserInfo where Id in (select FriendId from Friendship where MyId =:UserId)");
	query.bindValue(":UserId", QVariant(UserId));
	query.exec();
	QList<UserInfo> ListUserInfo;
	ListUserInfo.clear();
	while (query.next()) {
		ListUserInfo.append(UserInfo(query.value("Id").toInt(), query.value("Username").toString()));
	}
	return ListUserInfo;
}



//注册信息
void DataDB::registerUserInfo(const UserInfo& user) {
	QSqlQuery query;
    query.prepare("insert into UserInfo values(:Id,:Username,:pwd,:avatar)");
	query.bindValue(":Id", user.getID());
	query.bindValue(":Username", user.getName());
    query.bindValue(":pwd", user.getPwd());
    query.bindValue(":avatar", user.getAvatarName());
	query.exec();
}

//登录验证
bool DataDB::selectUserByIdAndPwd(const quint32 Id, const QString pwd) {
	QSqlQuery query;
	//向数据库发送一个预编译语句
	query.prepare("select * from UserInfo where Id =:Id and pwd =:pwd");
	query.bindValue(":Id", QVariant(Id));
	query.bindValue(":pwd", QVariant(pwd));
	query.exec();
	bool flag = query.next();
	qDebug() << flag;
	return flag;
}
//获得不含密码的基本信息
UserInfo DataDB::selectUserInfoById(const quint32 id){
    QSqlQuery query;
    //向数据库发送一个预编译语句
    query.prepare("select * from UserInfo where Id =:Id");
    query.bindValue(":Id", QVariant(id));
    query.exec();
    UserInfo tmp;
    while(query.next()){
        tmp = UserInfo(query.value("Id").toUInt(),
                       query.value("Username").toString(),
                       "",
                       query.value("Avatar").toString()
                       );
    }
    return tmp;
}

//添加好友 添加双向
void DataDB::addFriendship(quint32 Id1, quint32 Id2) {
	QSqlQuery query;
	query.prepare("insert into Friendship values(:Id1,:Id2)");
	query.bindValue(":Id1", QVariant(Id1));
	query.bindValue(":Id2", QVariant(Id2));
	query.exec();
	query.clear();
	query.prepare("insert into Friendship values(:Id1,:Id2)");
	query.bindValue(":Id1", QVariant(Id2));
	query.bindValue(":Id2", QVariant(Id1));
	query.exec();
}
//删除好友 双向删除
void DataDB::deleteFriendship(quint32 Id1, quint32 Id2) {
	QSqlQuery query;
	query.prepare("delete from Friendship where MyId =:Id1 and FriendId =:Id2");
	query.bindValue(":Id1", QVariant(Id1));
	query.bindValue(":Id2", QVariant(Id2));
	query.exec();
	query.clear();
	query.prepare("delete from Friendship where MyId =:Id1 and FriendId =:Id2");
	query.bindValue(":Id1", QVariant(Id2));
	query.bindValue(":Id2", QVariant(Id1));
	query.exec();
}
void DataDB::addMsg(quint32 Id1, quint32 Id2, QString Msg, QString Date) {
	QSqlQuery query;
	query.prepare("insert into Msg values(:Id1,:Id2,:Msg,:Date)");
	query.bindValue(":Id1", QVariant(Id1));
	query.bindValue(":Id2", QVariant(Id2));
	query.bindValue(":Msg", Msg);
	query.bindValue(":Date", Date);
	query.exec();
}

quint32 DataDB::selectMaxId() {
	QSqlQuery query;
	query.exec("select MAX(Id) as Id from UserInfo");
    quint32 maxId = quint32(100000);
	while (query.next()) {
        maxId = query.value("Id").toUInt();
	}
    Log::GetLogObj()->writeLog("[CurrentMaxID]" + QString::number(maxId));
    if(maxId>=quint32(100000)) return maxId;
    else return quint32(100000);
}


