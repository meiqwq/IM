#include "verifyutilities.h"

VerifyUtilities::VerifyUtilities()
{

}

//暂时没有写正则表达式验证是否有效的语句

bool VerifyUtilities::IsValidUsername(QString username){
    //不能含有、标点符号、或者是纯数字, 或者长度小于四位
    return true;
}

bool VerifyUtilities::IsValidPassword(QString password){
    //长度要够 不能含有1234 必须含有大小写字母
    return true;
}
