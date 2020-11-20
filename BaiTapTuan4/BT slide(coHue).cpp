#include<iostream>
using namespace std;

void xuat(int a[], int n){
	for(int i = 0; i< n; i++){
		cout << a[i] << "  ";
	}
}

void MinMax(int a[], int n, int &min, int &max){
	min = max = a[0];
	for(int i = 0; i < n; i++){
		if(a[i] > max)
			max = a[i];
		if(a[i] < min)
			min = a[i];
	}
}

void sapXepTang(int a[], int n){
	int tmp;
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(a[i] > a[j]){
				tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}


void tanSuat(int a[], int n, int min, int max){
	int b[1000];
	for(int i = 0; i <= max; i++){
		b[i] = 0;
	}
	for(int i = 0; i < n; i++){
		b[a[i]] ++;
	}
	int dem = b[0], index = 0;
	for(int i = 1; i <= max; i++){
		if(dem < b[i]){
			index = i;
			dem = b[i];
		}
	}
	for(int i = 0; i <= max; i++){
		if(b[i] == dem)
			cout << i << " ";
	}
}

int main(){
	int n = 10, a[n], max = 0, min = 0;
	cout << "Nhap mang: ";
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	cout << "Mang ban dau la: " << endl;
	xuat(a,n);
	cout << endl;
	MinMax(a,n,min,max);
	cout << "max : " << max << endl << "min : " << min << endl;
	cout <<"Cac so xuat hien nhieu nhat la: " ;
	tanSuat(a,n,min,max);
	cout << endl;
	cout <<"Mang sau sap xep theo gia tri tang dan la:" << endl;
	sapXepTang(a,n);
	xuat(a,n);
	cout << endl;
	return 0;
}
