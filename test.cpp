#include <iostream>
using namespace std;
class array
{
private:
    int n;
    int *data;

public:
    array(int _n, int _d); // ham tao
    ~array();              // ham huy
};
// dinh nghia ham tao ham huy
array ::array(int _n, int _d)
{
    n = _n;
    data = new int[n];
    for (int i = 0; i < n; i++)
    {
        data[i] = _d;
    }
}
array::~array()
{
    delete[] data;
}

int main()
{
    return 0;
}