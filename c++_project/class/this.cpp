/**
 *  C++ 对象模型和this指针
 * 
 * 1 . 成员变量和成员函数分开存储
 * 2. this 指针的概念
 * 
*/
#include <iostream>

using namespace std;
class Person {

};


class Person1 {
    int m_A;
};

class Person2 {
    int m_A;
    static int m_B;
};

class Person3 {
    int m_A;
    static int m_B;

    void func()
    {

    }
};

void test01()
{
    Person p;
    // 空对象的占用内存  sizeof p = 1
    // C++ 编译器会给每一个空对象分配一字节的空间，目的是为了区分不同的对象， 每一个空对象也要有一个独一无二的地址
    cout << "sizeof p = " << sizeof(p) << endl;

    Person1 p1;
    // sizeof p1 = 4 非静态成员属于对象上面
    cout << "sizeof p1 = " << sizeof(p1) << endl;

    Person1 p2;
    // sizeof p2 = 4 非静态成员属于对象上面, 静态成员变量不属于任何对象
    cout << "sizeof p2 = " << sizeof(p2) << endl;

    Person1 p3;
    // sizeof p3 = 4 非静态成员属于对象上面, 静态成员变量不属于任何对象, 成员变量和函数是分开存储的
    cout << "sizeof p3 = " << sizeof(p3) << endl;
}

/*
    成员变量和成员函数是分开存储的
    每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型的对象会共享一个块代码
    那么这一块代码如何区分那个对象调用自己？？？

    C++ 通过提供特殊的独享指针，this指针解决上述问题，this指针指向被调用的成员函数所属的对象
    this指针隐含每一个非静态成员函数内的一种指针
    this指针不需要定义，直接使用
*/

// this指针的作用  1. 解决名称冲突   2. 返回对象本身

class Person4 {
public:
    Person4(int age) {
        // this 谁调用指向谁，解决名称冲突， 但是还是推荐编码规范
        this->age = age;
    }

    /*
        返回指  Person4&  返回的是自己的引用
            Person4  返回的是一个对象，会调用对象的拷贝构造函数
    */
    Person4& PersonAddAge(Person4 &p)
    {
        this->age += p.age;
        // 返回对象本身
        return *this;
    }
    int age; // m_Age
};

void test02()
{
    Person4 p(18);

    cout << "age of p " << p.age << endl;

    Person4 p2(2);
    // 链式编程
    p.PersonAddAge(p2).PersonAddAge(p2);
    cout << "PersonAddAge age of p " << p.age << endl;
}
int main()
{
    test01();

    cout << "================" << endl;
    test02();
}