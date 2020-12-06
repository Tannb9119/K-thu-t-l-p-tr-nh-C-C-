#include <iostream>
#include <cmath>
using namespace std;

class Diem
{
private:
    int x, y;

public:
    void nhapsl()
    {
        cout << "Toa do x, y:";
        cin >> x >> y;
    }
    void in()
    {
        cout << "X: " << x << endl;
        cout << "Y: " << y << endl;
    }
    double dodai(Diem d2)
    {
        return sqrt(pow(x - d2.x, 2) + pow(y - d2.y, 2));
    }
};

class TamGiac
{
private:
    Diem d1, d2, d3;

public:
    void nhapdl()
    {
        d1.nhapsl();
        d2.nhapsl();
        d3.nhapsl();
    }
    void in()
    {
        cout << "Toa do d1" << endl;
        d1.in();
        cout << "Toa do d2" << endl;
        d2.in();
        cout << "Toa do d3" << endl;
        d3.in();
    }
    TamGiac()
    {
    }
    TamGiac(Diem a1, Diem a2, Diem a3)
    {
        d1 = a1;
        d2 = a2;
        d3 = a3;
    }
    double Area()
    {
        double a, b, c, p, s;
        a = d1.dodai(d2);
        b = d2.dodai(d3);
        c = d3.dodai(d1);
        p = (a + b + c) / 2;
        s = sqrt((p - a) * (p - b) * (p - c) * p);
        return s;
    }
    TamGiac &maxdt(TamGiac t2)
    {
        if (this->Area() > t2.Area())
            return *this;
        return t2;
    }
};

int main()
{
    int n;
    Diem *d;
    cout << "Nhap so diem n = ";
    cin >> n;
    d = new Diem[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap toa do diem thu " << i << ":";
        d[i].nhapsl();
    }
    TamGiac t, tmax;
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = i + 1; j < n - 1; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                t = TamGiac(d[i], d[j], d[k]);
                tmax = tmax.maxdt(t);
            }
        }
    }
    cout << "\nTam giac co dien tich lon nhat:" << endl;
    tmax.in();
    cout << "Dien Tich=" << tmax.Area() << endl;
    delete[] d;
    system("pause");
    return 0;
}