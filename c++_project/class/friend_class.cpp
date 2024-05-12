#include <iostream>
#include <string>

using namespace std;

/**
 * 类作友元
*/

class Building;
class GoodFriend {
public:
    GoodFriend();
    ~GoodFriend();
public:
    void visit();

    Building *building;
};

/*
friend_class.cpp:14:35: error: invalid use of incomplete type ‘class GoodFriend’
     friend void GoodFriend::visit();  // 只让GoodFriend的visit函数可以访问

 声明成员函数为友元需要直到成员函数的实现，需要把对应的类定义在前面
*/
// 声明类
class Building
{
    //friend class GoodFriend;  // 友元类可以访问该类的所有资源
    friend void GoodFriend::visit();  // 只让GoodFriend的visit函数可以访问
    public:
        Building();
    public:
        string m_sittingRoom;

    private:
        string m_bedRoom;
};

// 类外成员函数
Building::Building()
{
    this->m_sittingRoom = "sittingRoom";
    this->m_bedRoom = "bedRoom";
}



GoodFriend::GoodFriend()
{
    this->building = new Building;
}

void GoodFriend::visit()
{
    cout << "good friend visit " << this->building->m_sittingRoom << endl;
    // error: ‘std::__cxx11::string Building::m_bedRoom’ is private  不是友元不能访问，是友元可以访问
    cout << "good friend visit " << this->building->m_bedRoom << endl;
}
GoodFriend::~GoodFriend()
{
    delete this->building;
}

int main()
{
    GoodFriend f;
    f.visit();
}