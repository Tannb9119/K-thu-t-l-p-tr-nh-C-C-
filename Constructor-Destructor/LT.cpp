#include <iostream>
using namespace std;

class vector
{
	int n;
	float *v;

public:
	vector()
	{
		int i;
		cout << " Su dung ham tao khong doi:" << endl;
		cout << "Tao doi tuong :" << this << endl;
		cout << "So chieu:";
		cin >> n;
		v = new float[n];
		cout << "Xin cap phat bo nho " << n << " so thuc tai: " << v << endl;
		for (int i = 0; i < n; i++)
		{
			cout << "Toa do [" << i + 1 << "]:";
			cin >> v[i];
		}
	}
	vector(int size)
	{
		int i;
		cout << " Su dung ham tao 1 doi:" << endl;
		cout << "Tao doi tuong :" << this << endl;
		n = size;
		cout << "So chieu:" << n << endl;
		v = new float[n];
		cout << "Xin cap phat bo nho " << n << " so thuc tai" << v << endl;
		for (int i = 0; i < size; i++)
		{
			cout << "Toa do [" << i + 1 << "]:";
			cin >> v[i];
		}
	}
	vector(int size, float *a)
	{
		int i;
		cout << " Su dung ham tao 2 doi:" << endl;
		cout << "Tao doi tuong :" << this << endl;
		cout << "So chieu:" << size << endl;
		n = size;
		v = new float[size];
		cout << "Xin cap phat bo nho " << size << " so thuc tai" << v << endl;
		for (int i = 0; i < size; i++)
		{
			v[i] = a[i];
		}
	}
	vector(const vector &b)
	{
		int i;
		cout << "Su dung ham tao sao chep:" << endl;
		cout << "Tao doi tuong" << this << endl;
		v = new float[n = b.n];
		cout << "Xin cap phat bo nho" << n << " so thuc hien tai" << v << endl;

		for (int i = 0; i < n; i++)
		{
			v[i] = b.v[i];
		}
	}
	~vector()
	{
		cout << "\ncap phat bo nho " << n << " so thuc tai : " << v << endl;
		delete[] v;
	}
	void display()
	{
		int i;
		cout << "Doi tuong tai :" << this << endl;
		cout << "So chieu :" << n << endl;
		for (int i = 0; i < n; i++)
		{
			cout << v[i] << " ";
		}
	}
	vector &operator=(const vector &a)
	{
		if (n != a.n)
		{
			delete[] v;
			n = a.n;
			v = new float[n];
		}
		for (int i = 0; i < n; i++)
		{
			v[i] = a.v[i];
		}
		return *this;
	}
};

int main()
{
	float a[3] = {1, 2, 3};
	vector v1;
	v1.display();
	cout << "\n";
	vector v2(2);
	v2.display();
	cout << "\n";
	vector v3(2, a);
	v3.display();
	cout << "\n";
	vector v4(v1);
	v4.display();
	cout << endl;
	system("pause");
}