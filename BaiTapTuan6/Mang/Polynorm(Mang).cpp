#include <iostream>
#include <math.h>
#include <conio.h>
using namespace std;

double Polynorm(const double *a, int n, double x)
{
	double res = 0;
	for (int i = 0; i <= n; i++)
	{
		res += *(a + i) * pow(x, n - i);
	}
	return res;
}

int main()
{
	int n;
	double x;
	cout << "Nhap so phan tu cua mang: ";
	cin >> n;
	double *a = new double[n];
	for (int i = 0; i < n; i++)
	{
		cin >> *(a + i);
	}
	cout << "Nhap x = ";
	cin >> x;
	cout << "Gia tri bieu thuc ";
	for (int i = 0; i < n; i++)
	{
		cout << *(a + i) << "x^" << n - 1 - i;
		if (i != n - 1)
			cout << " + ";
	}
	cout << " = " << Polynorm(a, n - 1, x);
	getch();
	return 0;
}
