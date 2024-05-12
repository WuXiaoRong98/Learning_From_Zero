/**
 *   静态成员变量，所有对象共享同一份数据
 * 在编译阶段分配内存
 * 类内声明，类外初始化
 * 
*/

#include <iostream>

using namespace std;

class Person {
    public:

        // 所有对象共享同一份数据
        // 编译阶段分配内存
        // 类内声明，类外初始化
        static int m_A;  // 声明

        // 静态成员变量也有访问权限的，类外不能访问private成员变量
};

int Person::m_A = 100;

// 静态成语变量不属于任何对象，所有对象共享一份数据
// 因此静态成员变量有两种访问方式， 通过对象访问，通过类进行访问
void test1()
{
    cout << "Person::m_A = " << Person::m_A << endl;
}
int main()
{
    Person p;
    cout << "m_A = " << p.m_A << endl;

    p.m_A = 200;

    Person p1; 
    // 所有成员共享
    cout << " p1 m_A = " << p1.m_A << endl;

    test1();
}