#include <stdio.h>
#include <string.h>

int has_char(char str1[],char str2[]){
    int i,j;
    for(i=0;i<strlen(str1);i++){
        for(j=0;j<strlen(str2);j++){
            if(str1[i]==str2[j]){
                return 1;
            }
        }
    }
    return 0;
}

int main(void){
    char str1[50],str2[50];
    scanf("%s%s",str1,str2);
    int rv = has_char(str1,str2);
    if(rv){
        printf("Sim.\n");
    }
    else{
        printf("Nao.\n");
    }
    return 0;
}