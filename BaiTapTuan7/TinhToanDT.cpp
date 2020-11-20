#include <iostream>
#include <cmath>
using namespace std;

struct DT
{
    double a[20]; //Mang chua cac he so da thuc
    int n;        //bac da thuc
};
ostream &operator<<(ostream &os, DT d) // in da thuc
{
    for (int i = 0; i <= d.n; i++)
    {
        cout << d.a[i] << "x^" << i;
        if (i != d.n)
            cout << " + ";
    }
}
istream &operator>>(istream &is, DT &d) // nhap da thuc
{
    cout << "Nhap bac cua da thuc:";
    cin >> d.n;
    cout << "Nhap he so cua da thuc:";
    for (int i = 0; i <= d.n; i++)
    {
        cin >> d.a[i];
    }
}
DT operator-(const DT &d) // dao dau da thuc
{
    DT a;
    a.n = d.n;
    for (int i = 0; i <= d.n; i++)
    {
        a.a[i] = (-1) * d.a[i];
    }
    return a;
}
DT operator+(DT d1, DT d2) // cong hai da thuc
{
    DT d;
    d.n = (d1.n > d2.n) ? d1.n : d2.n;
    for (int i = 0; i <= d.n; i++)
    {
        d.a[i] = d1.a[i] + d2.a[i];
    }
    return d;
}
DT operator-(DT d1, DT d2) // tru hai da thuc
{
    DT d;
    d.n = (d1.n > d2.n) ? d1.n : d2.n;
    for (int i = 0; i <= d.n; i++)
    {
        d.a[i] = d1.a[i] - d2.a[i];
    }
    return d;
}
DT operator*(DT d1, DT d2)
{
    DT d;
    d.n = d1.n + d2.n;
    for (int i = 0; i <= d.n; i++)
        d.a[i] = 0;
    for (int i = 0; i <= d1.n; i++)
    {
        for (int j = 0; j <= d2.n; j++)
        {
            d.a[i + j] += d1.a[i] * d2.a[j];
        }
    }
    return d;
}
double operator^(DT d, double x)
{
    double sum = 0;
    for (int i = 0; i <= d.n; i++)
    {
        sum += d.a[i] * pow(x, d.n - i);
    }
    return sum;
}

void Init(DT &p, int n)
{
    for (int i = 0; i <= n; i++)
    {
        p.a[i] = 0;
    }
}

int main()
{
    struct DT p, q, r, s;
    struct DT f;
    Init(p, 20);
    Init(q, 20);
    Init(r, 20);
    Init(s, 20);
    cin >> p >> q >> r >> s;
    f = -(p + q) * (r - s);
    double a = f ^ 1;
    cout << "f = -(p + q) * (r - s)  = " << f;
    cout << endl;
    cout << "f = " << a;
    cout << endl;
    return 0;
}
