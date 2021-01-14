#include <iostream>
using namespace std;

class Date
{
public:
    int d, m, y;

public:
    Date() : d(0), m(0), y(0) {}
    Date(int _d, int _m, int _y) : d(_d), m(_m), y(_y) {}
    ~Date() {}
    friend ostream &operator<<(ostream &os, const Date &date)
    {
        if (date.d < 10)
            os << "0";
        os << date.d << "/";
        if (date.m < 10)
            os << "0";
        os << date.m << "/" << date.y;
        return os;
    }
};

class Vemaybay
{
private:
    string tenchuyen;
    Date ngaybay;
    int giave;

public:
    Vemaybay() {}
    Vemaybay(string _tenchuyen, Date _ngaybay, int _giave) : tenchuyen(_tenchuyen), ngaybay(_ngaybay), giave(_giave) {}
    ~Vemaybay() {}
    void output()
    {
        cout << "Ten chuyen:" << tenchuyen << endl;
        cout << "Ngay bay: " << ngaybay << endl;
        cout << "Gia ve: " << giave << endl;
    }
    void input()
    {
        cout << "Ten chuyen:";
        fflush(stdin);
        getline(cin, tenchuyen);
        cout << "Ngay: ";
        cin >> ngaybay.d;
        cout << "Thang: ";
        cin >> ngaybay.m;
        cout << "Nam: ";
        cin >> ngaybay.y;
        cout << "Gia ve:";
        cin >> giave;
    }
    int getgiave()
    {
        return giave;
    }
};

class Nguoi
{
private:
    string ten, gioitinh;
    int tuoi;

public:
    Nguoi()
    {
        ten = "";
        gioitinh = "";
        tuoi = 0;
    }
    ~Nguoi() {}
    Nguoi(string _ten, string _gioitinh, int _tuoi) : ten(_ten), gioitinh(_gioitinh), tuoi(_tuoi) {}
    void output()
    {
        cout << "Ten: " << ten;
        cout << endl
             << "Tuoi: " << tuoi << endl;
        cout << "Gioi tinh: " << gioitinh << endl;
    }
    void input()
    {
        cout << "Nhap ten: ";
        fflush(stdin);
        getline(cin, ten);
        cout << "Nhap gioi tinh: ";
        getline(cin, gioitinh);
        cout << "Nhap tuoi: ";
        cin >> tuoi;
    }
};

class Hanhkhach : public Nguoi
{
private:
    Vemaybay *ve;
    int soluong;
    int tongtien;

public:
    Hanhkhach() : Nguoi::Nguoi()
    {
        ve = NULL;
        soluong = 0;
        tongtien = 0;
    }
    Hanhkhach(int n)
    {
        soluong = n;
        ve = new Vemaybay[n];
    }
    ~Hanhkhach()
    {
        soluong = 0, tongtien = 0;
        delete[] ve;
    }
    Hanhkhach(const Hanhkhach &obj) : Nguoi::Nguoi(obj)
    {
        soluong = obj.soluong;
        tongtien = obj.tongtien;
        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; i++)
            ve[i] = obj.ve[i];
    }
    void input()
    {
        Nguoi::input();
        cout << "Nhap So Luong Ve Hanh Khach Da Mua: ";
        cin >> this->soluong;
        //ve = new Vemaybay[this->soluong];
        ve = new Vemaybay[this->soluong];
        for (int i = 0; i < this->soluong; ++i)
        {
            ve[i].input();
            tongtien += ve[i].getgiave();
        }
    }
    void output()
    {
        cout << "- Thong Tin Khach Hang: " << endl;
        Nguoi ::output();
        cout << "- Thong Tin Chuyen Bay: " << endl;
        for (int i = 0; i < this->soluong; ++i)
        {
            ve[i].output();
            cout << endl;
        }
        cout << "==> Tong Tien = " << this->tongtien;
        cout << endl;
    }

    bool operator<(const Hanhkhach &obj)
    {
        if (this->tongtien < obj.tongtien)
            return true;
        else
            return false;
    }
    Hanhkhach &operator=(Hanhkhach &obj)
    {
        delete[] ve;
        Nguoi::operator=(obj);
        soluong = obj.soluong;
        tongtien = obj.tongtien;
        ve = new Vemaybay[soluong];
        for (int i = 0; i < soluong; i++)
            ve[i] = obj.ve[i];
        return *this;
    }
    void Bubblesort(int n)
    {
        bool haveswap = false;
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                haveswap = false;
                if (this[j] < this[j + 1])
                {
                    Hanhkhach tmp = this[j];
                    this[j] = this[j + 1];
                    this[j + 1] = tmp;
                    haveswap = true;
                }
            }
            if (!haveswap)
                break;
        }
    }
};

int main()
{
    cout << "Nhap So Luong Khach Hang: ";
    int n;
    cin >> n;
    Hanhkhach *arr = new Hanhkhach[n];
    for (int i = 0; i < n; ++i)
        arr[i].input();
    for (int i = 0; i < n; ++i)
    {
        arr[i].output();
        cout << endl;
        cout << "------------------" << endl;
        cout << endl;
    }

    cout << "After Sort: " << endl;
    arr->Bubblesort(n);
    for (int i = 0; i < n; ++i)
    {
        arr[i].output();
        cout << "\n";
        cout << "------------------";
        cout << "\n\n";
    }
    return 0;
}