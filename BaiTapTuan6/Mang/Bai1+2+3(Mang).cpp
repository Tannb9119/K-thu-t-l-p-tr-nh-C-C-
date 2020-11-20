#include<iostream>
using namespace std;

void Print(const int* a, int n){
	for(int i = 0; i < n; i++){
		cout << *(a+i) << " ";
	}
}

int Sum(const int* a, int n){
	int sum = 0;
	for(int i = 0; i< n; i++)
		sum += *(a+i);
	return sum;
}

double Average(const int* a, int n){
	return 1.0*Sum(a,n) / n;
}

int main(){
	int n;
	cout <<"Nhap so phan tu cua mang n =";
	cin >> n;
	int *arr = new int[n];
	cout <<"Nhap mang:\n";
	for(int i = 0; i < n; i++){
		cout << "arr[" << i <<"] = ";
		cin >> arr[i];
	}
	cout <<"Mang ban vua nhap la:";
	Print(arr, n);
	cout << endl;
	cout <<"Tong cac phan tu trong mang la:" << Sum(arr, n);
	cout <<"\nTrung binh cong cac phan tu trong mang la:" << Average(arr, n);
	return 0;
}
