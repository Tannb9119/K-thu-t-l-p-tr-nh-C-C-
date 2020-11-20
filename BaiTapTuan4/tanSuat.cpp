#include<stdio.h>

void xoa(int a[], int pos, int * n){
	for(int i = pos; i < *n; i++){
		a[i] = a[i+1];
	}
	*n = *n-1;
}

int main(){
	int a[100], n, b[100], count, count1 = 0 ;
	printf("Nhap so phan tu: ");
	scanf("%d", &n);
	for(int i = 0; i< n ; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		count = 1;
		for(int j = i+1; j < n; j++){
			if(a[i] == a[j]){
				xoa(a, j, &n);
				count++;
				j--;
			}
		}
		b[count1++] = count;
	}
	for(int i = 0; i < count1; i++){
		printf("%d - %d \n",a[i],b[i]);
	}
	return 0;
}

