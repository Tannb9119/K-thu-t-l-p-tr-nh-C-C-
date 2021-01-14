#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class VanDongVien
{
private:
    string hoten;
    int tuoi;
    string monthidau;
    double cannang;
    double chieucao;

public:
    VanDongVien() { hoten = "", tuoi = 0, monthidau = "", cannang = 0, chieucao = 0; }
    VanDongVien(string name, int tuoi, string _monthidau, double cn, double cc) : hoten(name), monthidau(_monthidau), tuoi(tuoi), cannang(cn), chieucao(cc) {}
    ~VanDongVien() {}
    friend ostream &operator<<(ostream &os, const VanDongVien &vdv)
    {
        os << left << setw(20) << vdv.hoten;
        os << left << setw(10) << vdv.tuoi << left << setw(15) << vdv.monthidau << left << setw(8) << vdv.cannang;
        os << left << setw(8) << vdv.chieucao << endl;
        return os;
    }
    friend istream &operator>>(istream &is, VanDongVien &vdv)
    {
        cout << "Ho ten: ";
        fflush(stdin);
        getline(is, vdv.hoten);
        cout << "Tuoi: ";
        cin >> vdv.tuoi;
        fflush(stdin);
        cout << "Mon thi dau: ";
        getline(is, vdv.monthidau);
        cout << "Can nang: ";
        cin >> vdv.cannang;
        cout << "Chieu cao: ";
        cin >> vdv.chieucao;
        return is;
    }
    bool operator>(const VanDongVien &vdv)
    {
        if (chieucao > vdv.chieucao)
            return true;
        else if (chieucao == vdv.chieucao)
        {
            if (cannang > vdv.cannang)
                return true;
        }
        return false;
    }
    void sort(int n)
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n - i - 1; j++)
                if (this[j] > this[j + 1])
                {
                    VanDongVien tmp = this[i];
                    this[i] = this[i + 1];
                    this[i + 1] = tmp;
                }
    }
};

int main()
{
    VanDongVien p("Nguyen Van A", 20, "Bong Da", 178, 70.5);
    cout << p;

    cout << "Nhap So Luong: ";
    int n;
    cin >> n;
    VanDongVien *arr = new VanDongVien[n];

    for (int i = 0; i < n; ++i)
        cin >> arr[i];

    cout << endl
         << endl;
    for (int i = 0; i < n; ++i)
        cout << arr[i] << endl;

    cout << "Sort" << endl;
    arr->sort(n);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << endl;

    return 0;
}