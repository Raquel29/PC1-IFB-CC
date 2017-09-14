#include <stdio.h>
#include <string.h>

int my_strch(char str[],char ch){
    int i;
    int pos = -1;
    int n = strlen(str);
    for(i=0;i<n;i++){
        if(str[i]==ch){
            pos = i;
            break;
        }
    }
    return pos;
}

int main(void){
    char str[80];
    char ch;
    printf("Digite sua string: ");
    scanf("%79[^\n]%*c",str);
    printf("Digite um caractere: ");
    scanf("%c",&ch);
    int pos = my_strch(str,ch);
    if(pos==-1){
        printf("O caractere '%c' não ocorre em %s.\n",ch,str);
    }
    else{
        printf("A primeira ocorrência de '%c' em %s está na posição %d.\n",ch,str,pos);
    }
    return 0;
}
