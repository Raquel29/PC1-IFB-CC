#include <stdio.h>
#include <string.h>

void reverse(char str[]){
    int n = strlen(str);
    int i;
    for(i=0;i<n/2;i++){
        char ch = str[i];
        str[i] = str[n-i-1];
        str[n-i-1] = ch;
    }
}

void dec2bin(int n,char str[]){
    int i = 0;
    while(n){
        if(n%2 == 1){
            str[i]='1';
        }
        else{
            str[i]= '0';
        }
        n /= 2;
        i++;
    }
    str[i] = '\0';
    reverse(str);
}


int main(void){
    char str_binaria[65];
    int num;
    printf("Digite um número em decimal: ");
    scanf("%d",&num);
    dec2bin(num,str_binaria);
    printf("O valor em binario corresponde à: %s.\n",str_binaria);
    return 0;
}
