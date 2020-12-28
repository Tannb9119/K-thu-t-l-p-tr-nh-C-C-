
#include<iostream>
#include<math.h>
using namespace std;
#define _Display(x) x.Display(#x)
#define _Input(x) x.Input(#x)
class DT
{
private:
	int n;
	double* a;
public:
	DT() //ham tao khong doi
	{
		this->n = 0; this->a = NULL;
	}
	DT(int n1) //ham tao mot doi
	{
		this->n = n1;
		this->a = new double[n + 1];
	}
	DT(const DT& d)	//ham tao sao chep
	{
		this->n = d.n;
		this->a = new double[n + 1];
		for (int i = 0; i <= n; i++)
		{
			a[i] = d.a[i];
		}
	}
	~DT() // ham huy
	{
		this->n = 0;
		delete this->a;
	}
	friend ostream& operator<<(ostream& os, const DT& d); //ham toan tu in
	friend istream& operator>>(istream& is, DT& d); //ham toan tu nhap
	DT operator-(); //ham dao dau da thuc
	DT operator+(const DT& d2); //ham toan tu cong
	DT operator-(DT d2); //ham toan tu tru
	DT operator*(const DT& d2); // ham toan tu nhan
	double operator ^(const double& x); //gia tri da thuc tai x
	double operator[](int i) //truy nhap vao mot he so bat ky cua da thuc
	{
		if (i < 0)
			return double(n);
		else
			return a[i];
	}
	void Display(const char* name);
	void Input(const char* name);
	friend double F(DT p, double x);	//Ham tinh gia tri
	DT operator=(const DT& d2);	//toan tu gan
};

int main() {
	DT p,q(1),r,s(3);
	_Input(p);
	_Input(q);
	_Input(r);
	_Input(s);
	DT f = -(p + q) * (r - s);
	double X1 = 2.5, X2 = 2.5, g1, g2;
	_Display(f);
	g1 = f ^ X1;
	g2 = F(f, X2);
	cout << endl <<"X1 = 2.5 => f(X1) = f ^ X1 = "<< g1;
	cout << endl << "X2 = 2.5 => f(X2) = F(f, X2) = " << g2;
	DT g(f);
	cout << endl << "Ham g duoc tao sao chep tu ham f: " << g;
	return 0;
}
//
ostream& operator<<(ostream& os, const DT& d)
{
	if (d.n)
	{
		for (int i = 0; i < d.n; i++)
		{
			if (d.a[d.n - i] > 0)
			{
				if (d.a[d.n - i] - 1)
				{
					os << d.a[d.n - i];
				}

				os << "x^" << d.n - i;
			}
			else if (d.a[d.n - i] < 0)
			{
				if (!i)
				{
					os << " - ";
				}
				if (d.a[d.n - i] + 1)
				{
					os << -d.a[d.n - i];
				}
				os << "x^" << d.n - i;
			}
			if (d.a[d.n - i - 1] > 0)
			{
				os << " + ";
			}
			else if (d.a[d.n - i - 1] < 0)
			{
				os << " - ";
			}
		}
		if (d.a[0] < 0)
		{
			os << -d.a[0];
		}
		else if (d.a[0] > 0)
		{
			os << d.a[0];
		}
	}
	else
	{
		os << d.a[0];
	}
	return os;
}
void DT::Display(const char* name)
{
	cout << endl << "In da thuc " << name << ": " << *this;
}
istream& operator>>(istream& is, DT& d)
{
	if (!d.n)
	{
		cout << "   Bac da thuc: ";
		is >> d.n;
		d.a = new double[d.n + 1];
	}
	else
	{
		cout << "   Bac da thuc: " << d.n << endl;
	}
	cout << "   Cac he so da thuc: ";
	for (int i = 0; i <= d.n; i++)
	{
		is >> d.a[d.n - i];
	}
	return is;
}
void DT::Input(const char* name)
{
	cout << "Nhap da thuc " << name << ": " << endl;
	cin >> *this;
}

DT DT::operator-()
{
	for (int i = 0; i <= n; i++)
	{
		a[i] = -a[i];
	}
	return *this;
}

DT DT::operator+(const DT& d2)
{
	DT d3(n > d2.n ? n : d2.n);
	for (int i = 0; i <= d3.n; i++)
	{
		if (i <= n && i <= d2.n)
			d3.a[i] = a[i] + d2.a[i];
		else if (i > n)
			d3.a[i] = d2.a[i];
		else
			d3.a[i] = a[i];
	}
	while (!d3.a[d3.n] && d3.n > 0)
	{
		d3.n--;
	}
	return d3;
}

DT DT::operator-(DT d2)
{
	DT d3(n > d2.n ? n : d2.n);
	d3 = *this + (-d2);
	return d3;
}

DT DT::operator*(const DT& d2)
{
	DT d3(n + d2.n);
	for (int i = 0; i <= d3.n; i++)
	{	
		d3.a[i] = 0;
		for (int j = 0; j <= n; j++)
		{
			for (int k = 0; k <= d2.n; k++)
			{
				if (j+k==i)
				{
					d3.a[i] += a[j] * d2.a[k];
				}
			}
		}
	}
	return d3;
}

double DT::operator ^(const double& x)
{
	double GT = 0.0;
	for (int i = 0; i <= n; i++)
	{
		GT += a[i] * pow(x, i);
	}
	return GT;
}

double F(DT p, double x)
{
	double GT = 0.0;
	for (int i = 0; i <= p.n; i++)
	{
		GT += p.a[i] * pow(x, i);
	}
	return GT;
}

DT DT::operator=(const DT& d2)
{
	if (n!=d2.n)
	{
		delete[]a;
		n = d2.n;
		a = new double[n + 1];
	}
	for (int i = 0; i <= n; i++)
	{
		a[i] = d2.a[i];
	}
	return *this;
}
