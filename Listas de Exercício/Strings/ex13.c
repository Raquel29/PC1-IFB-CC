#include <stdio.h>
#include <string.h>

void find(char text[],char pattern[]){
    int i,j;
    int n = strlen(text);
    int m = strlen(pattern);
    for(i=0;i<n-m+1;i++){
        int ocorre = 1;
        for(j=0;j<m;j++){
            if(pattern[j]!=text[i+j]){
                ocorre = 0;
                break;
            }
        }
        if(ocorre){
            printf("%s ocorre em %s na posição %d.\n",pattern,text,i);
        }
    }
}

int main(void){
    char text[80];
    char pattern[80];
    printf("Digite o texto: ");
    scanf("%79[^\n]%*c",text);
    printf("Digite o padrao: ");
    scanf("%79[^\n]%*c",pattern);
    find(text,pattern);
    return 0;
}
