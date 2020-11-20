#include <iostream>
#include <string.h>
using namespace std;

char *ToUpper(const char *s)
{
	char *a = new char[strlen(s)];
	for (int i = 0; i < strlen(s); i++)
	{
		a[i] = s[i];
	}
	for (int i = 0; i < strlen(s); i++)
	{
		if (a[i] >= 97 && a[i] <= 122)
			a[i] = a[i] - 32;
	}
	return a;
}

int main()
{
	char a[100];
	cout << "Moi ban nhap xau:";
	cin.getline(a, 99);
	char *s = a;
	cout << ToUpper(s);
	return 0;
}
