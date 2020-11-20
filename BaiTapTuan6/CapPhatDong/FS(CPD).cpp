#include<iostream>
using namespace std;

int* FS(int n){
	int* fs = new int[n];
	int a1 = 1, a2 = 2, tmp = 0, count = 2;
	if(n == 1)
		*fs = 1;
	if(n > 1){
		*fs = 1;
		*(fs+1) = 2;
		while(count != n){
			tmp = a1 + a2;
			a1 = a2;
			a2 = tmp;
			*(fs + count++) = tmp; 
		}
	}
	return fs;
}

int main(){
	int* fs = FS(8);
	for(int i = 0; i < 8 ; i++)
		cout << *(fs + i) <<" ";
	return 0;
}

