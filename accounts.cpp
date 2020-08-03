#include <iostream>
#include <string>
#include "exceptions.hpp"
using namespace std;
enum adm{
    ADMIN,
    DEBUGGER,
    PRO,
    USER,
};
class account {
private:
    string accName;
    string hashValue;
    adm pros;
public:
    void regist(string name,adm pros=adm::USER) {
        // TODO: 注册账户(现在没电了看不了文档 ( (
        //! throw exceptions in exceptions.hpp:
        //* accountExist - 账户已存在
        //* invalidAccountName - 不被允许的账户名
        //* insuffPermissions - 权限不足
        
    }
    void logout(string name) {
        // TODO: 注销账户. 只有DEBUGGER和ADMIN可以注销任何账户
        // PRO账户可以注销USER账户, 反之不可行
        //! throw exceptions:
        //* insuffPermissions - 权限不足
        //* 账户不存在 
    }
    void rename(string oldName, string name) {
        // TODO: 修改名字
        //!throw exceptions:
        //* 账户不存在(oldName)
        //* accountExist - 账户已存在 (name)
        //* invalidAccountName - 不被允许的账户名
    }
    void printAccInfo() {
        // TODO: 打印账户信息
    }
};
