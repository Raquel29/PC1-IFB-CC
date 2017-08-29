#include <stdio.h>

int main(void){
    for(int i=0;i<9;i++){
        int num_estrela;
        int num_espaco;
        if(i<5){
            num_estrela = 2*i+1;
            num_espaco = 9-num_estrela;
        }
        else{
            num_estrela = 9 - 2*(i-5+1);
            num_espaco = 9 - num_estrela;
        }
        int j;
        for(j=0;j<num_espaco/2;j++){
            printf(" ");
        }
        for(j=0;j<num_estrela;j++){
            printf("*");
        }
        for(j=0;j<num_espaco/2;j++){
            printf(" ");
        }
        printf("\n");
    }
    return 0;
}
