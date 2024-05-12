/*
    const 修饰成员函数
        常函数：
            成员函数后加const 后称这个函数为常函数
            常函数不可以修改成员属性
            成员数据声明加关键字mutable后，在常函数中依然可以修改

        常对象
            声明对象前加const称该对象为常对象
            常对象只能调用常函数
*/

#include <iostream>

using namespace std;

class Person {
    public:
    // this指针的本质是一个指针常量  Person *const this  --> this不能指向其他对象
    // const Person *const this  this 指向的值也不能通过this修改
    void showPerson() const
    {
        // error: assignment of member ‘Person::m_Age’ in read-only object
        //this->m_Age = 100;  // 常函数不能修改成员属性
        cout << "const member function" << endl;
        this->m_B = 100;
    }

    void func()
    {
        this->m_Age = 100;
    }

    int m_Age;
    mutable int m_B;  // 加上关键字mutable之后可以在常函数里面修改

};

int main()
{
    Person p;
    p.showPerson();

    const Person p1 = p;
    //  error: passing ‘const Person’ as ‘this’ argument discards qualifiers
    // 普通成员函数是可以修改成员属性的，危险行为，加了const之后是不可以修改的，所以报错
   // p1.func();
   p1.showPerson(); // 常对象只能调用常函数
    
}