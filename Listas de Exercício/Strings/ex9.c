#include <stdio.h>


int bin2dec(char str[]){
    int num = 0;
    int i;
    for(i=0; str[i]!='\0'; i++){
        num = 2*num + str[i]-'0';
    }
    return num;
}


int main(void){
    char str_binaria[65];
    printf("Digite um número binário: ");
    scanf("%64[^\n]",str_binaria);
    printf("O valor em decimal corresponde à: %d.\n",bin2dec(str_binaria));
    return 0;
}
