#include<stdio.h>
#include<string.h>
int main()
{
	char s1[100],s2[100];
	printf("Nhap xau s1: ");
	gets(s1);
	strcpy(s2,s1);
	printf("s2: %s",s2);
	return 0;
}
