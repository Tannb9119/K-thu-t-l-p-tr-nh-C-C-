#include <iostream>
#include <string>
using namespace std;
class TS
{
public:
    TS();
    ~TS();
    TS &operator=(const TS &t);
    void Sapxep(int n);
    void Nhap(int n);
    void Display(int n);
    void BoSung(int &n);

private:
    string Ten;
    double Diem;
};
int main()
{
    int n;
    cout << "Nhap so thi sinh: ";
    cin >> n;
    TS *ts = new TS[n + 1];
    ts->Nhap(n);
    ts->Sapxep(n);
    ts->Display(n);
    ts->BoSung(n);
    ts->Sapxep(n);
    ts->Display(n);
    return 0;
}

TS::TS()
{
    this->Ten = "";
    this->Diem = 0;
}

TS::~TS()
{
    this->Ten = "";
    this->Diem = 0;
}

TS &TS::operator=(const TS &t)
{
    Diem = t.Diem;
    Ten = t.Ten;
    return *this;
}

void TS::Sapxep(int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (this[i].Diem < this[j].Diem)
            {
                TS x = this[i];
                this[i] = this[j];
                this[j] = x;
            }
        }
    }
}

void TS::Nhap(int n)
{
    cout << "Nhap thong tin " << n << " thi sinh: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "   - Thi sinh " << i + 1 << ": " << endl;
        getchar();
        cout << "     + Ho ten: ";
        getline(cin, this[i].Ten);
        cout << "     + Tong diem: ";
        cin >> this[i].Diem;
    }
}

void TS::Display(int n)
{
    cout << "   In danh sach thi sinh sau khi sap xep: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i + 1 << ". " << this[i].Ten << " - " << this[i].Diem << " diem" << endl;
    }
}

void TS::BoSung(int &n)
{
    cout << endl
         << "* Bo sung 1 thi sinh: " << endl;
    cout << "     + Ho ten: ";
    getchar();
    getline(cin, this[n].Ten);
    cout << "     + Tong diem: ";
    cin >> this[n].Diem;
    n++;
}
