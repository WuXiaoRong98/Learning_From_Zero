/*
  静态成员函数
    - 所有对象共享一个哈数
    - 静态成员函数只能访问静态成员变量
*/
#include <iostream>

using namespace std;

class Person {
    public:
        // 静态成员函数
        static void func()
        {
            cout << " static void func()" << endl;
            m_A = 100;

            //  error: invalid use of member ‘Person::m_B’ in static member function
            // 静态成员函数不能访问非静态成员变量
           // m_B = 200;
        }

        static int m_A; // 静态成员变量， 不属于任何对象，共享的
        int m_B;   // 非静态成员, 属于特定对象上

        // 静态成员函数也是有访问权限的
    private:
        static void func1()
        {

        }
};


int Person::m_A = 0;
void test()
{
    // 访问方式， 对象或者类调用
    Person p;
    p.func();

    Person::func();

    // error: ‘static void Person::func1()’ is private
    //Person::func1();

}

int main()
{
    test();
    return 0;
}