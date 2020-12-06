#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

class TS
{
private:
    char name[30];
    double mark;

public:
    TS()
    {
        strcpy(name, "");
        mark = 0;
    }
    TS(char name[], double mark)
    {
        strcpy(name, name);
        this->mark = mark;
    }
    double getMark();
    void nhap();
    void in();
    TS &operator=(const TS &a);
    void swap(TS &a);
    ~TS() {}
};

double TS::getMark()
{
    return mark;
}

TS &TS::operator=(const TS &a)
{
    strcpy(name, a.name);
    mark = a.mark;
}

void TS::nhap()
{
    cout << "Name: ";
    fflush(stdin);
    cin.getline(name, 29);
    cout << "Mark: ";
    cin >> mark;
}

void TS::in()
{
    cout << name << "\t\t" << mark << endl;
}

void TS::swap(TS &a)
{
    TS tmp;
    tmp = *this;
    *this = a;
    a = tmp;
}

void sort(TS *ts, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (ts[i].getMark() < ts[j].getMark())
                ts[i].swap(ts[j]);
        }
    }
}

int main()
{
    TS *ts;
    int n;
    cout << "Nhap so luong thi sinh:";
    cin >> n;
    ts = (TS *)malloc(n * sizeof(TS));
    for (int i = 0; i < n; i++)
    {
        cout << "Nhap thong tin thi sinh thu " << i << " :" << endl;
        ts[i].nhap();
    }
    cout << "DS thi sinh vua nhap la: " << endl;
    cout << "STT \tName \t\t\t Mark" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t";
        ts[i].in();
    }
    sort(ts, n);
    cout << "DS ts sau khi sap xep la:" << endl;
    cout << "STT \tName \t\t\t Mark" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t";
        ts[i].in();
    }
    TS a;
    cout << "Nhap thong tin thi sinh muon them:" << endl;
    a.nhap();
    ts = (TS *)realloc(ts, (n + 1) * sizeof(TS));
    ts[n] = a;
    n++;
    sort(ts, n);
    cout << "DS thi sinh sau khi them la: " << endl;
    cout << "STT \tName \t\t\t Mark" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << i << "\t";
        ts[i].in();
    }
    return 0;
}