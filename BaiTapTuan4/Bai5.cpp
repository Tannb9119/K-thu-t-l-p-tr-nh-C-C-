#include<stdio.h>
#include<string.h>
int main()
{
	char s[100], s1[100][100];
	gets(s);
	int i, dem = 0, dem1 = 0;
	for(i = 0; i < strlen(s); i++){
		if(s[i] == ' '){
			dem++;
			dem1 = 0;
			continue;
		}
		s1[dem][dem1++] = s[i];
	}
	for(i=0;i<dem+1;i++){
		printf("s[%d]:%s\n",i,s1[i]);
	}
	return 0;
}

