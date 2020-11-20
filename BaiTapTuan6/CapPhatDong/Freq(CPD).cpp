#include<iostream>
#include<string.h>
using namespace std;

int* Freq(const char* s){
	int n = strlen(s);
	char* a = new char[n];
	int* ts = new int[n];
	for(int i = 0; i < n; i++){
		ts[i] = 1;
		a[i] = s[i];
	}
	int count = 1;
	for(int i = 0; i < n; i++){
		count = 1;
		if(a[i] != ' '){
			for(int j = i + 1; j < n; j++){
				if(a[i] == a[j]){
					a[j] = ' ';
					ts[i] = ++count;
				}
			}
		}
	}
	return ts;
}

int main(){
	char* s= "aaabbebccckkdeeerrrer";
	int* ts = Freq(s);
	for(int i = 0; i < strlen(s); i++){
		int check = 1;
		for(int j = 0; j < i; j++){
			if(s[i] == s[j])
				check = 0;
		}
		if(check)
			cout <<*(s+i) << " xuat hien "<< *(ts+i) << "lan\n";
	}
	return 0;
}

