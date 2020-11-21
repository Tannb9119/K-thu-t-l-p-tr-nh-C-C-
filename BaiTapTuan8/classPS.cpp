#include <iostream>
#include <cmath>
using namespace std;

class PS
{
private:
    int a, b;

public:
    friend istream &operator>>(istream &, PS &);
    friend ostream &operator<<(ostream &, PS);
    friend int uscln(int, int);
    friend PS rutgon(PS &);
    friend PS operator+(PS, PS);
    friend PS operator-(PS, PS);
    friend PS operator*(PS, PS);
    friend PS operator/(PS, PS);
};
istream &operator>>(istream &is, PS &p) // ham nhap
{
    is >> p.a >> p.b;
    return is;
}

ostream &operator<<(ostream &os, PS p)
{
    os << p.a << "/" << p.b;
    return os;
}

int uscln(int x, int y)
{
    x = abs(x);
    y = abs(y);
    while (x != y)
    {
        if (x > y)
            x = x - y;
        else
            y = y - x;
    }
    return x;
}

PS rutgon(PS &p)
{
    int k = uscln(p.a, p.b);
    p.a = p.a / k;
    p.b = p.b / k;
    return p;
}

PS operator+(PS p1, PS p2)
{
    PS p;
    p.a = p1.a * p2.b + p2.a * p1.b;
    p.b = p1.b * p2.b;
    return rutgon(p);
}
PS operator-(PS p1, PS p2)
{
    PS p;
    p.a = p1.a * p2.b - p2.a * p1.b;
    p.b = p1.b * p2.b;
    return rutgon(p);
}
PS operator*(PS p1, PS p2)
{
    PS p;
    p.a = p1.a * p2.a;
    p.b = p1.b * p2.b;
    return rutgon(p);
}
PS operator/(PS p1, PS p2)
{
    PS p;
    p.a = p1.a * p2.b;
    p.b = p1.b * p2.a;
    return rutgon(p);
}

int main()
{
    PS p, q, z, u, v;
    PS s, tmp;
    cout << "\nNhap phan so p: ";
    cin >> p;
    cout << "\nNhap phan so q: ";
    cin >> q;
    cout << "\nNhap phan so z: ";
    cin >> z;
    cout << "\nNhap phan so u: ";
    cin >> u;
    cout << "\nNhap phan so v: ";
    cin >> v;
    s = (p - q * z) / (u + v);
    cout << "\nPhan so s = (p - q * z) / (u + v) = " << s << endl;
    system("pause");
}
