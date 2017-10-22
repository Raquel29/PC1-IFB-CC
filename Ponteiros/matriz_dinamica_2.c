#include <stdio.h>
#include <stdlib.h>

int** aloca_matriz(int l,int c){
	int** mat;
	int i;
	mat = malloc( l * sizeof(int*));
	mat[0] = malloc(l*c*sizeof(int));
	for(i=1;i<l;i++){
		mat[i] = &(mat[0][c*i]);
	}
	return mat;
}

void preenche_matriz(int** m,int l,int c){
	int i,j,k;
	k = 0;
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			m[i][j] = k++;
		}
	}
}

void imprime_matriz(int** m,int l,int c){
	int i,j;
	for(i=0;i<l;i++){
		for(j=0;j<c;j++){
			printf("%d ",m[i][j]);
		}
		printf("\n");
	}
}

void libera_matriz(int** m){
	free(m[0]);
	free(m);
}


int main(void){
	int** matriz = aloca_matriz(10,5);
	preenche_matriz(matriz,10,5);
	imprime_matriz(matriz,10,5);
	libera_matriz(matriz);
	return 0;
}