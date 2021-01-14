#include <iostream>
using namespace std;

template <class ope>
int *toArr(int a[], int n, int x, int &count, ope OP)
{
    int dem = 0;
    for (int i = 0; i < n; i++)
        if (OP(a[i], x))
            dem++;
    count = dem;
    int *arr = new int[dem];
    int j = 0;
    for (int i = 0; i < n; i++)
        if (OP(a[i], x))
            arr[j++] = a[i];
    return arr;
}

bool beHon(const int &a, int &x)
{
    if (a < x)
        return true;
    return false;
}

bool lonHon(const int &a, int &x)
{
    if (a > x)
        return true;
    return false;
}

bool chiaHet(const int &a, int &x)
{
    if (a % x == 0)
        return true;
    return false;
}

bool koChiaHet(const int &a, int &x)
{
    if (a % x != 0)
        return true;
    return false;
}

int main()
{
    // int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9}; // Mang tinh
    int n, count = 0;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int *arr = toArr(a, n, 3, count, beHon); // cau a
    for (int i = 0; i < count; i++)
        cout << arr[i] << endl;
    return 0;
}