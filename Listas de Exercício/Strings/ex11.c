#include <stdio.h>


int hex2dec(char str[]){
    int num = 0;
    int i;
    for(i=0; str[i]!='\0'; i++){
        if('a'<=str[i] && str[i]<='f'){
            num = 16*num + (str[i]-'a'+10);
        }
        else{
            num = 16*num +  (str[i]-'0');
        }
    }
    return num;
}


int main(void){
    char str_hexa[65];
    printf("Digite um número hexadecimal: ");
    scanf("%64[^\n]",str_hexa);
    printf("O valor em decimal corresponde à: %d.\n",hex2dec(str_hexa));
    return 0;
}
