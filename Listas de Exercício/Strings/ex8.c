#include <stdio.h>
#include <string.h>

void my_strcpy(char str2[],char str1[]){
    int n = strlen(str1);
    int i;
    for(i=0;i<n;i++){
        str2[i] = str1[i];
    }
}

int main(void){
    char str1[80];
    char str2[80];
    printf("Digite a primeira string: ");
    scanf("%79[^\n]%*c",str1);
    my_strcpy(str2,str1);
    printf("A segunda string corresponde a: %s.\n",str2);
    return 0;
}
