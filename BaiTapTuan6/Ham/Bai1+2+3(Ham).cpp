#include<iostream>
using namespace std;

double Pow(double x, int n){
	if(n == 1)
		return x;
	return x*Pow(x, n-1);
}

int Fatorial(int n){
	if(n == 1)
		return 1;
	return n*Fatorial(n-1);
}

int Fibonacci(int n){
	if(n == 1 || n == 2)
		return 1;
	return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main(){
	cout << "2^4 = " << Pow(2,4) << endl;
	cout << "5! = " << Fatorial(5) <<endl;
	cout <<"So Fibonacci thu 6 = " <<Fibonacci(6) <<endl;
	return 0;
}

