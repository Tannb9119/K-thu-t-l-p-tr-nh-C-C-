#include<stdio.h>
#include<stdlib.h>
int main(){
	float* f = (float*)malloc(sizeof(float));
	int index = 0;
	do{
		scanf("%f", f+index++);
		getchar();
		char c;
		printf("Ban co muon nhap tiep(C/K): ");
		scanf("%c",&c);
		getchar();
		if(c == 'K' || c == 'k')
			break;
		else
			f = (float*)realloc(f, sizeof(f) + 4);
	}while(1);
	for(int i = 0; i < index; i++){
		printf("%f ",*(f + i));
	}
	return 0;
}
