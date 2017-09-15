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

void dec2hex(int n,char str[]){
    int i = 0;
    while(n){
        if(n%16 >=10 ){
            str[i]='a' + (n%16-10);
        }
        else{
            str[i] = '0' + n%16;
        }
        n /= 16;
        i++;
    }
    str[i] = '\0';
    reverse(str);
}


int main(void){
    char str_hexa[65];
    int num;
    printf("Digite um número em decimal: ");
    scanf("%d",&num);
    dec2hex(num,str_hexa);
    printf("O valor em hexadecimal corresponde à: %s.\n",str_hexa);
    return 0;
}
