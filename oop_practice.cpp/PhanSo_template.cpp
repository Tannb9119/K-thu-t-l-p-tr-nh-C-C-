#include <iostream>
using namespace std;

class PhanSo
{
private:
    int tuso;
    int mauso;

public:
    PhanSo() {}
    ~PhanSo() {}
    PhanSo(int a = 0, int b = 0) : tuso(a), mauso(b) {}
    int UCLN(int a, int b)
    {
        while (a != b)
        {
            if (a > b)
                a -= b;
            else
                b -= a;
        }
        return a;
    }
    friend ostream &operator<<(ostream &os, const PhanSo &ps)
    {
        os << ps.tuso << "/" << ps.mauso;
        return os;
    }
    friend istream &operator>>(istream &is, PhanSo &ps)
    {
        cout << "Nhap tu so :";
        is >> ps.tuso;
        cout << "Nhap mau so :";
        is >> ps.mauso;
    }
    PhanSo &operator+(const PhanSo &a)
    {
        tuso = tuso * a.mauso + a.tuso * mauso;
        mauso = mauso * a.mauso;
        this->rutGon();
        return *this;
    }
    PhanSo &operator-(const PhanSo &a)
    {
        tuso = tuso * a.mauso - a.tuso * mauso;
        mauso *= a.mauso;
        this->rutGon();
        return *this;
    }
    PhanSo &operator*(const PhanSo &a)
    {
        tuso *= a.tuso;
        mauso *= a.mauso;
        this->rutGon();
        return *this;
    }
    PhanSo &operator/(const PhanSo &a)
    {
        tuso *= a.mauso;
        mauso *= a.tuso;
        this->rutGon();
        return *this;
    }
    PhanSo &rutGon()
    {
        int k = UCLN(tuso, mauso);
        tuso /= k;
        mauso /= k;
        return *this;
    }
};

int main()
{
    PhanSo obj1(5, 2), obj2(3, 5);
    cout << obj1 - obj2;
}