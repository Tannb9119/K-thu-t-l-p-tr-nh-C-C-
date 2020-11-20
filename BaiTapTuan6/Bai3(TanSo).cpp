#include<iostream>
using namespace std;

void nhap(int n, int *a){
	for(int i = 0; i < n; i++){
		cout << "Nhap phan tu thu " << i<<":";
		cin >> *(a+i);
	}
}

int* sapxep(int n, int *a){
	int *p = a;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(*(p+i) > *(p+j) ){
				int tmp = *(p+i);
				*(p+i) = *(p+j);
				*(p+j) = tmp;
			}
		}
	}
	return p;
}

int** tansuat(int n, int*a){
	int**ts = new int*[2];
	for(int i = 0; i < 2; i++){
		*(ts + i) = new int[n];
	}
	sapxep(n, a);
	for(int i = 0; i < n; i++){
		*(*ts+i) = *(a+i);
		*(*(ts + 1) + i) = 1;
	}
	int f = 1; 
	for(int i = 0 ; i < n; i++){
		f = 1;
		if(*(*ts + i) != 0){
			for(int j = i+1; j < n; j++){
				if(*(*ts + i) == *(*ts + j)){
					*(*ts + j) = 0;
					f++;
					*(*(ts + 1) + i) = f; 
				}
			}
		}
	}
	return ts;
}

int main(){
	int n, i;
	int *a ;
	int *b, **ts;
	cout << "Nhap kich thuoc mang a:";
	cin >> n;
	a = new int[n];
	nhap(n, a);
	cout << "Mang da nhap: ";
	for(int i = 0; i < n; i++){
		cout << a[i] <<" ";
	}
	cout <<endl;
	b = sapxep(n, a);
	cout << "Mang da sap xep: ";
	for(int i = 0; i < n; i++){
		cout << b[i] <<" ";
	}
	cout << endl;
	ts = tansuat(n,a);
	for(int i = 0; i < n; i++){
		if(ts[0][i] != 0)
		cout << "So " << ts[0][i] << " xuat hien " << ts[1][i] <<  " lan" << endl;
	}
	return 0;
}
