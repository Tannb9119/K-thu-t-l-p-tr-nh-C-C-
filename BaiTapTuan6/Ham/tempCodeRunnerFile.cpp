#include <stdio.h>
#include <stdlib.h>
int Sum(const int *a, int n)
{
	int i, S = 0;
	for (i = 0; i < n; i++)
	{
		S += a[i];
	}
	return S;
}
int main()
{
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc(n * sizeof(int));
	int i;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	printf("%d", Sum(a, n));
	return 0;
}
