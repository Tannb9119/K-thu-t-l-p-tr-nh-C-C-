#include <iostream>
using namespace std;

template <class T>
class Complex
{
private:
    T real, imag;

public:
    Complex<T>(T _real = 0.0, T _imag = 0.0) : real(_real), imag(_imag) {}
    Complex<T>(const Complex<T> &c)
    {
        real = c.real;
        imag = c.imag;
    }
    Complex<T> operator-() const
    {
        real = -1 * real;
        imag = -1 * imag;
    }
    Complex<T> &operator+=(const Complex<T> &a)
    {
        real += a.real;
        imag += a.imag;
        return *this;
    }
    Complex<T> &operator-=(const Complex<T> &a)
    {
        real -= a.real;
        imag -= a.imag;
        return *this;
    }
    Complex<T> &operator*=(const Complex<T> &a)
    {
        real = real * a.real - imag * a.imag;
        imag = real * a.imag + imag * a.real;
        return *this;
    }
    Complex<T> &operator/=(const Complex<T> &a)
    {
        real = (double)(real * a.real + imag * a.imag) / (pow(a.real, 2) + pow(a.imag, 2));
        imag = (double)(-real * a.imag + imag * a.real) / (pow(a.real, 2) + pow(a.imag, 2));
        return *this;
    }
    template <typename U>
    friend ostream &operator<<(ostream &os, const Complex<U> &a)
    {
        os << a.real;
        if (a.imag >= 0)
            os << "+";
        os << a.imag;
        os << "i";
        return os;
    }
};

int main()
{
    Complex<double> a(3.5, 4.5), b(2.5, 4.5);
    a += b;
    cout << a;
    return 0;
}