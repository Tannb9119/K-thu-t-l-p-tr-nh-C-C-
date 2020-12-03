#include <iostream>
using namespace std;

class TestPointer
{
private:
    int a, b;

public:
    TestPointer(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    TestPointer &ThietLapGiaTriA(int x)
    {
        a = x;
        return *this;
    }
    TestPointer &ThietLapGiaTriB(int x)
    {
        b = x;
        return *this;
    }
    void HienThi()
    {
        cout << "Gia tri a:" << a << endl;
        cout << "Gia tri b:" << b << endl;
    }
};

int main()
{
    cout << "---------Thong tin doi tuong P------------" << endl;
    TestPointer p(4, 8);
    p.HienThi();
    cout << "Thong tin doi tuong p sau khi thiet lap lai gia tri:" << endl;
    p.ThietLapGiaTriA(10).ThietLapGiaTriB(30);
    p.HienThi();
    return 0;
}