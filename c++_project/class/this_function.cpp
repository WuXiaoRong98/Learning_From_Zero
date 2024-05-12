/*
    空指针访问成员函数

     C++是可以通过空指针访问成员函数的
*/

#include <iostream>

using namespace std;

class Persion {
    public:
        void showClassName()
        {
            cout << "this is Person class" << endl;
        }

        void showPersonAge() 
        {
            // 防止传空指针
            if (this == NULL) {
                return;
            }
            // 访问成员变量的时候默认都会有this指针指向， 所以导致空指针访问函数报错
            cout << "age = " << this->m_Age << endl;
        }

        int m_Age;

};


void test()
{
    Persion *p = NULL;  // 空指针是可以访问成员函数的

    /*
        调用第一个函数的时候没有问题，调用第二个函数出现段错误 
    */
    p->showClassName();
    p->showPersonAge();
}

int main()
{
    test();
}