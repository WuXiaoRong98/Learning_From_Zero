#include <iostream>

using namespace std;


class Phone {
    public:
        Phone(string name) {
            cout << "Phone(string name):m_PName(name)" << endl;
            m_PName = name;
        }
        ~Phone()
        {
            cout << "~Phone()" << endl;
        }
        string m_PName;
};

class Person {
    public:
        // m_Phone = pNmae  隐式转换法 pNmae 是一个字符串   m_Phone 是一个对象， 而Phone class正好有一个对应的string的有参构造函数
        // 初始化列表
        Person(string name, string pNmae):m_Name(name), m_Phone(pNmae)
        {
            cout << "Person(string name, string pNmae):m_Name(name), m_Phone(pNmae)" << endl;
        }
        ~Person()
        {
            cout << "~Person()" << endl;
        }
        string m_Name;
        Phone m_Phone;
};


// 当其他类做类类的成员变量，则先构造其他类的构造函数
// 析构函数相反， 先析构自己的，再析构其他类
/**
 *  Phone(string name):m_PName(name)
    Person(string name, string pNmae):m_Name(name), m_Phone(pNmae)
    张三 === Iphone
    ~Person()
    ~Phone()
*/
void test()
{
    Person p1("张三", "Iphone");
    cout << p1.m_Name << " === " << p1.m_Phone.m_PName << endl;
}

int main(int argc, char *argv[])
{
    test();
    return 0;
}