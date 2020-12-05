#include <iostream>
#include <cmath>
using namespace std;

class Complex
{
private:
    double real;
    double imag;

public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}
    Complex operator+(const Complex &b) const
    {
        Complex z(real + b.real, imag + b.imag);
        return z;
    }
    Complex operator-(const Complex &b) const
    {
        return Complex(real - b.real, imag - b.imag);
    }
    Complex operator*(const Complex &b) const
    {
        Complex a;
        a.real = real * b.real - imag * b.imag;
        a.imag = real * b.imag + imag * b.real;
        return a;
    }
    Complex operator/(const Complex &b) const
    {
        Complex a;
        a.real = (double)(real * b.real + imag * b.imag) / (pow(b.real, 2) + pow(b.imag, 2));
        a.imag = (double)(-real * b.imag + imag * b.real) / (pow(b.real, 2) + pow(b.imag, 2));
        return a;
    }
    Complex &operator+=(const Complex &b)
    {
        real = real + b.real;
        imag = imag + b.imag;
        return *this;
    }
    Complex &operator-=(const Complex &b)
    {
        real = real - b.real;
        imag = imag - b.imag;
        return *this;
    }
    friend ostream &operator<<(ostream &os, Complex &b)
    {
        os << b.real << " + " << b.imag << "i";
        return os;
    }
    friend istream &operator>>(istream &is, Complex &b)
    {
        cout << "Real: ";
        is >> b.real;
        cout << "Imag: ";
        is >> b.imag;
        return is;
    }
};

int main()
{
    Complex a, b, c, d, e;
    cin >> b;
    cout << "b = " << b << endl;
    cin >> c;
    cout << "c = " << c << endl;
    cin >> d;
    cout << "d = " << d << endl;
    cin >> e;
    cout << "e = " << e << endl;
    a = b * c + (d - e);
    cout << "a = b*c +(d - e) = " << a << endl;
    return 0;
}