#include <iostream>
using namespace std;

template <class T, class OP>
void operation(T *p1, T *p2, T *result, int n, OP op)
{
    for (int i = 0; i < n; i++)
    {
        result[i] = op(p1[i], p2[i]);
    }
}

template <class T>
T add(const T &a, const T &b)
{
    return a + b;
}

template <class T>
struct Add
{
    T operator()(const T &a, const T &b) { return a + b; }
};

template <class T>
void display(const T &a, int n)
{
    for (int i = 0; i < n; i++)
        cout << "\t" << a[i];
    cout << endl;
}

int main()
{
    int a[5] = {1, 2, 3, 4, 5};
    int b[5] = {11, 12, 13, 14, 15};
    int result[5];
    operation(a, b, result, 5, add<int>);
    display(result, 5);
    operation(a, b, result, 5, Add<int>());
    display(result, 5);
    system("pause");
    return 0;
}