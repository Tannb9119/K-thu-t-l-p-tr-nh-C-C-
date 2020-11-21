#include <iostream>
using namespace std;

class HinhCN
{
private:
    int d, r;

public:
    void nhapsl()
    {
        cout << "Nhap chieu dai, rong:";
        cin >> d >> r;
    }
    void in()
    {
        cout << "Chieu dai:" << d << endl;
        cout << "Chieu rong:" << r << endl;
    }
    int getArea()
    {
        return d * r;
    }
    int getPerimeter()
    {
        return 2 * (d + r);
    }
};

class DayHCN
{
private:
    int n;
    HinhCN *h;

public:
    void nhapsl()
    {
        cout << "Nhap so luong hinh chu nhat n:";
        cin >> n;
        h = new HinhCN[n];
        for (int i = 0; i < n; i++)
        {
            h[i].nhapsl();
        }
    }
    HinhCN dtMax()
    {
        int Max = h[0].getArea();
        int index = 0;
        for (int i = 1; i < n; i++)
        {
            if (Max < h[i].getArea())
            {
                Max = h[i].getArea();
                index = i;
            }
        }
        return h[index];
    }
    HinhCN *cvMax()
    {
        int Max = h[0].getPerimeter();
        int index = 0;
        for (int i = 1; i < n; i++)
        {
            if (Max < h[i].getPerimeter())
            {
                Max = h[i].getPerimeter();
                index = i;
            }
        }
        return h + index;
    }
};

int main()
{
    DayHCN a;
    a.nhapsl();
    cout << "Kich thuoc HCN co chu vi lon nhat la:" << endl;
    HinhCN *c = a.cvMax();
    c->in();
    cout << "Chu vi max = ";
    cout << a.cvMax()->getPerimeter() << endl;
    cout << "Kich thuoc HCN co dien tich lon nhat la:" << endl;
    HinhCN s = a.dtMax();
    s.in();
    cout << "Dien tich max = ";
    cout << a.dtMax().getArea() << endl;
    return 0;
}