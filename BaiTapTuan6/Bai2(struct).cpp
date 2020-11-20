#include<iostream>
using namespace std;

struct thiSinh{
	char ten[30];
	double tongDiem;
};

void swap(struct thiSinh &a, struct thiSinh &b){
	struct thiSinh tmp;
	tmp = a;
	a = b;
	b = tmp;
}

struct thiSinh nhap(){
	struct thiSinh a;
	cout << "Nhap ten thi sinh:";
	cin.getline(a.ten, 29);
	cout <<"Nhap tong diem:";
	cin >> a.tongDiem;
	cin.ignore();
	return a;
}

void sort(thiSinh dsts[], int n){
	for(int i = 0; i < n - 1; i++){
		for(int j = i+1; j < n; j++){
			if(dsts[i].tongDiem < dsts[j].tongDiem)
				swap(dsts[i], dsts[j]);
		}
	}
}

int main(){
	int n;
	double diemChuan;
	cout <<"Nhap so luong thi sinh n = ";
	cin >> n;
	cout <<"Nhap diem chuan trung tuyen:";
	cin >> diemChuan;
	fflush(stdin);
	struct thiSinh dsts[n];
	for(int i = 0; i < n; i++){
		dsts[i] = nhap();
	}
	cout <<"==================================" << endl;
	cout <<"Danh sach thi sinh vua nhap la:\n";
	for(int i = 0; i < n; i++)
		cout << dsts[i].ten << " - " << dsts[i].tongDiem << " diem" << endl;
	cout <<"==================================" << endl;
	cout <<"DS thi sinh sau khi sap xep la: \n";
	sort(dsts, n);
	for(int i = 0; i < n; i++)
		cout << dsts[i].ten << " - " << dsts[i].tongDiem << " diem" << endl;
	cout << "===================================" << endl;
	cout <<"DS thi sinh trung tuyen la:\n";
	int dem = 1;
	for(int i = 0; i < n; i++){
		if(dsts[i].tongDiem >= diemChuan){
			cout << dem++ <<". " << dsts[i].ten << endl; 
		}
	}
	return 0;
}
