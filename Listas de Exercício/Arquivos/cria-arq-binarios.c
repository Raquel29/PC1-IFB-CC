#include <stdio.h>


int main(){
	int v1[] = {1,3,5,7,9};
	int v2[] = {2,4,6,8,10};
	FILE* arq1 = fopen("arq1","wb");
	FILE* arq2 = fopen("arq2","wb");
	fwrite(v1,sizeof(int),5,arq1);
	fwrite(v2,sizeof(int),5,arq2);
	return 0;
}