#include <stdio.h>

int main(void){
    int i;
    for(i=1;i<=9;i++){
        int j,k;
        if(i<=5){
            j = i;
        }
        else{
            j = 10-i;
        }
        for(k=1;k<=j;k++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
