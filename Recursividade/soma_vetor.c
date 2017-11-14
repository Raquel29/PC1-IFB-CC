#include <stdio.h>

int soma(int* v,int n){
	if(n==0){
		return 0;
	}
	return v[0] + soma(&v[1],n-1);
}

int soma2(int* v,int n){
	if(n==0){
		return 0;
	}
	return v[n-1] + soma(v,n-1);
}

int soma3(int* v, int n){
	return v[n]+soma3(v,n-1);
}


int main(void){
	int v[] = {1,3,4,2,6,5};
	printf("Soma de v = %d\n",soma(v,6));
	printf("Soma de v = %d\n",soma2(v,6));
	printf("Soma de v = %d\n",soma3(v,5));
	return 0;
}
