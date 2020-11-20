#include<stdio.h>

int main()
{
	int n;
	printf("Nhap so phan tu cua mang:");
	scanf("%d",&n);
	int A[100],i;
	for(i=0;i<n;i++){
		scanf("%d",&A[i]);
	}
	for(i=0;i<n;i++)
	printf("%d ",A[n-i-1]);
	return 0;
}
