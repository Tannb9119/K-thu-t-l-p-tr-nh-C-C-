#include<iostream>
#include<cmath>
using namespace std;

int Root(double a, double b, double c, double* x1, double* x2){
	if(a == 0){
		if(b == 0){
			if(c != 0)
				return 0;
			else 
				return -1;
		}
		else{
			*x1 = *x2 = -c/b;
			return 1;
		}
	}
	else{
		double delta = b*b - 4*a*c;
		if(delta < 0)
			return 0;
		else if(delta == 0){
			*x1 = *x2 = -b/2*a;
			return 1;
		}
		else{
			*x1 = (-b + sqrt(delta)) / 2*a;
			*x2 = (-b - sqrt(delta)) / 2*a;
			return 2;
		}
	}
}

int main(){
	double a, b, c, x1, x2;
	cout <<"Nhap he so cua phuong trinh ax^2 + bx + c = 0 : ";
	cin >> a >> b >> c;
	if(Root(a,b,c,&x1,&x2) == 0)
		cout <<"Phuong trinh vo nghiem";
	else if(Root(a,b,c,&x1,&x2) == -1)
		cout <<"Phuong trinh vo so nghiem";
	else if(Root(a,b,c,&x1,&x2) == 1)
		cout <<"Phuong trinh co 1 nghiem x = " << x1;
	else 
		cout <<"Phuong trinh co 2 nghiem x1 = " << x1 << ", " << "x2 = " << x2;
	return 0;
}
