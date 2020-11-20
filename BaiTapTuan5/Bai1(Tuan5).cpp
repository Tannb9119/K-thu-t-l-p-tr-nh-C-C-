#include<iostream>
using namespace std;

void sort(int a[]){
	int tmp;
	for(int i = 0; i < 10; i++){
		for(int j = 9; j > i; j--){
			if(a[j] < a[j-1]){
				tmp = a[j];
				a[j] = a[j-1];
				a[j-1] = tmp;
			}
		}
	}
}

void InitTS(int ts[2][10], int a[10]){
	for(int j = 0; j < 10; j++){
		ts[0][j] = a[j];
		ts[1][j] = 1;
	}
	int dd = 1;
	for(int i = 0; i < 9; i++){
		for(int j = i+1; j < 10; j++){
			if(a[i] == a[j]){
				dd++;
				ts[1][i] = dd;
				ts[0][j] = 0;
			}
		}
		dd = 1;
	}
}

int MaxTS(int ts[2][10]){
	int max = ts[1][0];
	for(int i = 0; i < 10; i++){
		if(max < ts[1][i]){
			max = ts[1][i];
		}
	}
	return max;
}

void showResult(int ts[2][10], int a[10]){
	sort(a);
	InitTS(ts,a);
	int max = MaxTS(ts);
	cout << "Gia tri lon nhat: " << a[9] <<"\nGia tri nho nhat: " << a[0];
	cout << endl;
	cout <<"In mang da sap xep:\n";
	for(int i = 0; i < 10; i++){
		cout << a[i] <<" ";
	}
	cout << endl;
	cout << "Tan suat xuat hien cac phan tu\n";
	for(int j = 0; j < 10; j++){
		if(ts[0][j] != 0){
			cout << "So " << ts[0][j] << " xuat hien " << ts[1][j] <<" lan" << endl; 
		}
	}
	if(max > 1){
		cout << "Gia tri xuat hien nhieu nhat la: ";
		for(int k = 0; k < 10; k++){
			if(ts[1][k] == max){
				cout << ts[0][k] << ", ";
			}
		}
		cout << "xuat hien " << max << " lan." << endl;	
	}
	if(max == 1)
		cout << "Cac so chi xuat hien 1 lan" << endl;
}

int main(){
	int a[10];
	int ts[2][10];
	cout << "Nhap vao 10 so nguyen\n";
	for(int i = 0; i < 10; i++){
		cout << "Gia tri " << i << " la : ";
		cin >> a[i];
	}
	showResult(ts, a);
	return 0;
}
