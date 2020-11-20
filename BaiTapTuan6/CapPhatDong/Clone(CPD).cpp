#include <iostream>
using namespace std;

int *Clone(const int *a)
{
	int n = 0;
	while (*(a + n) != 0)
		n++;
	int *s = new int[n];
	for (int i = 0; i < n; i++)
	{
		s[i] = a[i];
	}
	return s;
}

int main()
{
	int a[] = {1, 3, 5, 6, 1, 12, 25, 37, 18, 67, 10};
	int *s = Clone(a);
	int n = sizeof(a) / sizeof(int);
	for (int i = 0; i < n; i++)
		cout << *(s + i) << " ";
	return 0;
}
