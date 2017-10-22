#include <stdio.h>
#include <stdlib.h>

void aloca_vetor(int** ptr,int n){
	*ptr = malloc(sizeof(int) * n);
	if(ptr==NULL){
		perror("Erro: ");
		exit(EXIT_FAILURE);
	}
	int i;
	for(i=0;i<n;i++){
		(*ptr)[i] = i;
	}
}

int main(void){
	int* ptr;
	int i;
	aloca_vetor(&ptr,10);
	for(i=0;i<10;i++){
		printf("%d ",ptr[i]);
	}
	printf("\n");
	return 0;
}