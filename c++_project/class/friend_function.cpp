/*
 友元
    关键字 friend

    私有属性运行类外的一些函数或者类进行访问，就需要定义友元函数

    友元的三种实现：
        - 全局友元函数
        - 类作友元
        - 成员函数作友元

*/

#include <iostream>
#include <string>

using namespace std;

class Bulding {

    // 声明goodFriends为该类的友元函数，就可以访问private私有属性
    friend void goodFriends(Bulding *building);
    public:
        Bulding()
        {
            m_sittingRoom = "sittingRoom";
            m_bedRoom = "bedRoom";
        }
        string m_sittingRoom;

    private:
        string m_bedRoom;
};

// 全局函数

void goodFriends(Bulding *building)
{
    cout << "goodFriends visted  Bulding" << endl;
    cout << building->m_sittingRoom << endl;

    // 普通函数不能访问   error: ‘std::__cxx11::string Bulding::m_bedRoom’ is private
    // 友元的话就可以访问
    cout << building->m_bedRoom << endl;
}

int main()
{
    Bulding b;

    goodFriends(&b);

}