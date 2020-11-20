#include <iostream>
#include <string.h>
using namespace std;

typedef int MT[20][20];
void nhapmt(MT a, char *ten, int m, int n)
{
    cout << "Nhap ma tran " << ten << ":" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "phan tu"
                 << "[" << i << "]"
                 << "[" << j << "] = ";
            cin >> a[i][j];
        }
    }
};
void inmt(MT a, char *ten, int m, int n)
{
    cout << "Ma tran " << ten << " :" << endl;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}
void nhapmt(MT a, char *ten, int n)
{
    cout << "Nhap ma tran " << ten << ":" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "phan tu"
                 << "[" << i << "]"
                 << "[" << j << "] = ";
            cin >> a[i][j];
        }
    }
}
void inmt(MT a, char *ten, int n)
{
    cout << "Ma tran " << ten << " :" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << a[i][j] << "  ";
        }
        cout << endl;
    }
}
void nhanmt(MT a, MT b, MT c, int m, int n, int p)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < p; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}
void nhanmt(MT a, MT b, MT c, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c[i][j] = 0;
            for (int k = 0; k < n; k++)
            {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
}

int main()
{
    MT a, b, c, d, tmp;
    int m = 2, n = 2, p = 3;
    char A[] = "A2x2";
    char B[] = "B2x2";
    char C[] = "C2x3";
    nhapmt(a, A, m);
    inmt(a, A, m);
    nhapmt(b, B, m);
    inmt(b, B, m);
    nhapmt(c, C, n, p);
    inmt(c, C, n, p);
    nhanmt(a, b, tmp, m);
    nhanmt(tmp, c, d, m, n, p);
    char D[] = "D = AxBxC la";
    inmt(d, D, m, p);
    system("pause");
    return 0;
}