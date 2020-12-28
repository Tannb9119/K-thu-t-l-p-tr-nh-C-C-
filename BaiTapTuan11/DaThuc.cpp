#include <iostream>
#include <cmath>
#include <stdlib.h>
using namespace std;

class DT
{
private:
    int n;
    double *a;

public:
    DT();
    DT(const DT &d);                                // Ham tao sao chep
    double *getPtr();                               // Ham lay he so cua da thuc
    int getN();                                     // Ham lay so bac cua da thuc
    friend ostream &operator<<(ostream &os, DT &d); // Ham toan tu xuat
    friend istream &operator>>(istream &is, DT &d); // Ham toan tu nhap
    DT &operator-();                                // Dao dau da thuc
    DT operator+(DT &d);                            // nap chong toan tu cong
    DT operator-(DT &d);                            // nap chong toan tu tru
    DT operator*(const DT &d);                      // nap chong toan tu nhan
    double operator^(const double &x);              // nap chong toan tu mu de tinh gia tri da thuc tai x
    double operator[](int i);                       // nap chong toan tu [] tra ve he so
    DT &operator=(const DT &d);                     // Ham gan
    ~DT()                                           // Ham huy
    {
        cout << "Huy bo nho " << n + 1 << " so thuc tai: " << a << " cua doi tuong: " << this << endl;
        delete[] a;
    }
    void display(); //Hien thi
};

void DT::display()
{
    cout << "Doi tuong tai:" << this << endl;
    cout << "So bac da thuc: " << n << endl;
    cout << "Vung nho cua he so:" << a << endl;
    cout << "He so:" << endl;
    for (int i = 0; i <= n; i++)
        cout << a[i] << " ";
}

double *DT::getPtr()
{
    return a;
}

int DT::getN()
{
    return n;
}

DT::DT()
{
    cout << "Tao doi tuong tai: " << this << endl;
    this->n = 0;
    this->a = NULL;
}

DT::DT(const DT &d)
{
    this->n = d.n;
    this->a = new double[n + 1];
    for (int i = 0; i <= n; i++)
    {
        a[i] = d.a[i];
    }
}

DT &DT::operator=(const DT &d)
{
    if (n != d.n)
    {
        delete[] a;
        n = d.n;
        a = new double[n + 1];
    }
    for (int i = 0; i <= d.n; i++)
    {
        a[i] = d.a[i];
    }
    return *this;
}

ostream &operator<<(ostream &os, DT &d)
{
    for (int i = 0; i <= d.n; i++)
    {
        os << d.a[i] << "x^" << i;
        if (i != d.n)
            os << " + ";
    }
    return os;
}

istream &operator>>(istream &is, DT &d)
{
    cout << "Nhap bac cua da thuc:";
    is >> d.n;
    d.a = new double[d.n + 1];
    cout << "Nhap he so cua da thuc:";
    for (int i = 0; i <= d.n; i++)
    {
        is >> d.a[i];
    }
    return is;
}

DT &DT::operator-()
{
    for (int i = 0; i <= n; i++)
        a[i] = (-1) * a[i];
    return *this;
}

DT DT::operator+(DT &d)
{
    DT d1;
    int i, k;
    k = (n > d.n) ? n : d.n;
    d1.a = new double[k + 1];
    for (i = 0; i <= k; i++)
    {
        if (i <= n && i <= d.n)
            d1.a[i] = d.a[i] + a[i];
        else if (i <= n)
            d1.a[i] = a[i];
        else
            d1.a[i] = d.a[i];
    }
    i--;
    while (i > 0 && d1.a[i] == 0)
        i--;
    d1.n = i;
    return d1;
}

DT DT::operator-(DT &d)
{
    DT d1;
    int i, k;
    k = (n > d.n) ? n : d.n;
    d1.a = new double[k + 1];
    for (i = 0; i <= k; i++)
    {
        if (i <= n && i <= d.n)
            d1.a[i] = a[i] - d.a[i];
        else if (i <= n)
            d1.a[i] = a[i];
        else
            d1.a[i] = -d.a[i];
    }
    i--;
    while (i > 0 && d1.a[i] == 0)
        i--;
    d1.n = i;
    return d1;
}

DT DT::operator*(const DT &d)
{
    DT d1;
    d1.n = d.n + n;
    d1.a = new double[d1.n + 1];
    for (int i = 0; i <= d1.n; i++)
        d1.a[i] = 0;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= d.n; j++)
        {
            d1.a[i + j] += a[i] * d.a[j];
        }
    }
    return d1;
}

double DT::operator^(const double &x)
{
    double p = 0;
    for (int i = 0; i <= this->n; i++)
    {
        p += pow(x, i) * this->a[i];
    }
    return p;
}

double DT::operator[](int i)
{
    if (i < 0)
        return (double)n;
    else
        return this->a[i];
}

double F(DT p, double x)
{
    double a = 0;
    int n = p.getN();
    for (int i = 0; i <= n; i++)
    {
        a += pow(x, i) * p[i];
    }
    return a;
}

int main()
{
    DT p, q, r, s, f;
    double x1, x2;
    cin >> p;
    p.display();
    cout << endl;
    cout << "===============================" << endl;
    cin >> q;
    q.display();
    cout << endl;
    cout << "===============================" << endl;
    cin >> r;
    r.display();
    cout << endl;
    cout << "===============================" << endl;
    cin >> s;
    s.display();
    cout << endl;
    cout << "===============================" << endl;
    f = -(p + q) * (r - s);
    cout << "Nhap x1 = ";
    cin >> x1;
    cout << "Nhap x2 = ";
    cin >> x2;
    double a = f ^ x1;
    cout << "f = -(p + q) * (r - s)  = " << f << endl;
    cout << "f(x1) = " << a << endl;
    cout << "f(x2) = " << F(f, x2) << endl;
    return 0;
}
