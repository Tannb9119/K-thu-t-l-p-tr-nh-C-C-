#include<stdio.h>
#include<string.h>
int main()
{
	char s1[100],s2[100];
	printf("Nhap xau s1: ");
	gets(s1);
	printf("Nhap xau s2: ");
	gets(s2);
	if(strcmp(s1,s2)==0)
		printf("hai xau giong nhau");
	else
		printf("hai xau khong bang nhau");
	return 0;
}
