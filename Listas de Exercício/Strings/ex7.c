#include <stdio.h>
#include <string.h>

int my_strch(char str[],char ch,int pos_inicio){
    int i;
    int pos = -1;
    int n = strlen(str);
    for(i=pos_inicio;i<n;i++){
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
    int pos_inicio;
    printf("Digite sua string: ");
    scanf("%79[^\n]%*c",str);
    printf("Digite um caractere: ");
    scanf("%c",&ch);
    printf("Digite uma posição: ");
    scanf("%d",&pos_inicio);

    int pos = my_strch(str,ch,pos_inicio);
    if(pos==-1){
        printf("O caractere '%c' não ocorre em %s a partir da posição %d.\n",ch,str,pos_inicio);
    }
    else{
        printf("A primeira ocorrência de '%c' em %s após a posição %d está na posição %d.\n",ch,str,pos_inicio,pos);
    }
    return 0;
}
