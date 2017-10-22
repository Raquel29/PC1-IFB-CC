#include <stdio.h>
#include <stdlib.h>

int* aloca_matriz(int l,int c){
	int* v = malloc(l*c*sizeof(int));
	return v;
}

void preenche_matriz(int* m,int l,int c){
	int i,j;
	int k = 0;
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			//m[i][j] = k++
			m[i*c + j] = k++;
		}
	}
}

void imprime_matriz(int* m,int l,int c){
	int i,j;
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			//m[i][j] = k++
			printf("%d ",m[i*c + j]);
		}
		printf("\n");
	}
}


void libera_matriz(int* m){
	free(m);
}
int main(void){
	int* v = aloca_matriz(5,5);
	preenche_matriz(v,5,5);
	imprime_matriz(v,5,5);
	libera_matriz(v);
	return 0;
}