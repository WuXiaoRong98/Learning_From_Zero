#include <iostream>

using namespace std;

class CirCle {
    public:

    private:
        int m_R;
        int m_x;
        int m_y;
};

int main(int argc, char *argv[])
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << (a + b + c) / 3 << endl;
    return 0;
}