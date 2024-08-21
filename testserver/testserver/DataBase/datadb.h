#ifndef DATADB_H
#define DATADB_H
#include <QSqlDatabase>

#include "DataModel/datamodel.h"

class DataDB
{
public:
    explicit DataDB();
    ~DataDB();
    //登录功能数据库
    bool selectUserByIdAndPwd(const quint32 id, const QString pwd);//存在返回true，不存在返回false
    UserInfo selectUserInfoById(const quint32 id);//存在返回true，不存在返回false
    //查询当前全部用户的数据库操作--静态sql
    QList<UserInfo> selectAllFriendsUserInfo(quint32 UserId);
    //注册
    void registerUserInfo(const UserInfo& user);//一个用户结构题
    //添加好友
    void addFriendship(quint32 Id1,quint32 Id2);//两个好友的Id
    //删除好友
    void deleteFriendship(quint32 Id1,quint32 Id2);//两个好友的Id
    //添加聊天信息
    void addMsg(quint32 Id1,quint32 Id2,QString Msg,QString Date);//发送者的Id，接收者的Id，聊天信息，标准日期xxxx-xx-xx xx:xx:xx使用库获取日期
    //获取最大的Id值
    quint32 selectMaxId();
    //单例设计模式--应对数据库的对象的内存使用
    static DataDB* GetInstance();
    //邱睿桥给我她的struct之后，我写一个QList返回她需要的结构列表
private:
    QSqlDatabase sqldb;
    static DataDB* db;
};

#endif // DATADB_H
