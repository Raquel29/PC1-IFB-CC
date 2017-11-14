#include <stdio.h>

int fibr(int n){
	if(n<=2){
		return 1;
	}
	return fibr(n-1)+fibr(n-2);
}

int fibi(int n){
	if(n<=2){
		return 1;
	}
	int res;
	int aux1 = 1,aux2 = 1;
	int i;
	for(i=3;i<=n;i++){
		res = aux1+aux2;
		aux2 = aux1;
		aux1 = res;
	}	
	return res;
}

int main(void){
	printf("Fib iterativo = %d\n",fibi(100));
	printf("Fib recursivo = %d\n",fibr(100));
	return 0;
}