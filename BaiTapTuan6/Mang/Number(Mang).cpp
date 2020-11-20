#include<iostream>
#include<string.h>
#include<cmath>
using namespace std;

double Number(const char* a){
	int count = 0, count1 = 0;
	char* s = new char[strlen(a)];
	for(int i = 0; i < strlen(a); i++){
		s[i] = a[i];
	}
	for(int i = 0; i < strlen(s); i++){
		if(s[i] == '.')
			count++;// dem so dau phay
		if(count == 1 && s[i] != '.')
			count1++; // dem so chu so phia sau dau phay dau tien
		if(count == 2)
			s[i] = '\0';// xoa bo cac phan tu tu dau phay thu 2;
	}
	double number = 0;
	for(int i = strlen(s) - 1; i >= 0; i--){
		 if(a[i] != '.'){
		 	number += (int)(s[i] - '0')*pow(10,(-1)*count1);
		 	count1--;
		}
	}
	return number;
}

int main(){
	char a[] = "15.3678.4567";
	char* s = a;
	cout << Number(a) + 1;
	return 0;
}

