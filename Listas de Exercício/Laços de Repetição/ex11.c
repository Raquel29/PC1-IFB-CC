#include <stdio.h>

int main(void){

    int n;

    printf("Digite o valor a ser convertido para algarismos romanos: ");
    scanf("%d",&n);

    if(n<1 || n>=4000){
        printf("Este valor não pode ser convertido para romano.\n");
        return 0;
    }

    while(n>=1000){
        printf("M");
        n-=1000;
    }
    if(n>=900){
        printf("CM");
        n-=900;
    }
    if(n>=500){
        printf("D");
        n-=500;
        while(n>=100){
            printf("C");
            n-=100;
        }
    }
    if(n>=400){
        printf("CD");
        n-=400;
    }
    while(n>=100){
        printf("C");
        n-=100;
    }
    if(n>=90){
        printf("XC");
        n-=90;
    }
    if(n>=50){
        printf("L");
        n-=50;
        while(n>=10){
            printf("X");
            n-=10;
        }
    }
    if(n>=40){
        printf("XL");
        n-=40;
    }
    while(n>=10){
        printf("X");
        n-=10;
    }
    if(n>=9){
        printf("IX");
        n-=9;
    }
    if(n>=5){
        printf("V");
        n-=5;
        while(n>=5){
            printf("I");
            n--;
        }
    }
    if(n>=4){
        printf("IV");
        n-=4;
    }
    while(n){
        printf("I");
        n--;
    }
    printf("\n");
    return 0;
}
