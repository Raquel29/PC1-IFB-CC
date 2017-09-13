#include <stdio.h>

int count_lastnames(char str[]){
    int count = 0;
    int i = 0;
    int ultimo_espaco = -1;
    while(str[i]!='\0'){
        /** Vai para o proximo caractere diferente de espaco
            ou fim da string **/
        while(str[i]==' ' && str[i]!='\0'){
            i++;
        }
        if(str[i]!='\0'){
            if(ultimo_espaco!=-1){
                count++;
            }
            ultimo_espaco = i;
        }
        /** Vai para o proximo caractere espaco ou fim da string**/
        while(str[i]!=' ' && str[i]!='\0'){
            i++;
        }
    }
    return count;
}

int main(void){
    char nome[80];
    printf("Digite um nome completo: ");
    scanf("%79[^\n]s",nome);
    printf("O nome %s possui %d sobrenomes",nome,count_lastnames(nome));
    return 0;
}
