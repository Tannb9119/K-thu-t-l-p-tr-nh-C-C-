#include <iostream>
#include <stdlib.h>
using namespace std;

void ChinhSua(double *a, int k, int n) // cap phat lai bo nho
{
    double b[k];
    for (int i = 0; i < k; i++)
    {
        b[i] = a[i];
    }
    delete[] a;
    a = new double[n];
    for (int i = 0; i < n; i++)
    {
        if (i < k)
            a[i] = b[i];
        else
        {
            a[i] = 0;
        }
    }
}

int main()
{
    int n = 3;
    double *a = new double[n];
    for (int i = 0; i < n; i++)
        a[i] = 1;
    ChinhSua(a, n, n + 1);
    for (int i = 0; i < n + 1; i++)
        cout << a[i] << " ";
    return 0;
}