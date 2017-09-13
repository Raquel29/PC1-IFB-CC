#include <stdio.h>
#include <string.h>
void my_strcat(char str1[],char str2[]){
    int i,j;
    for(i=strlen(str1),j=0;j<strlen(str2);j++,i++){
        str1[i] = str2[j];
    }
}

int main(void){
    char str1[160];
    char str2[80];
    printf("Digite a primeira string: ");
    scanf("%79[^\n]%*c",str1);
    printf("Digite a segunda string: ");
    scanf("%79[^\n]%*c",str2);
    my_strcat(str1,str2);
    printf("A string concatenada corresponde a: %s.\n",str1);
    return 0;
}
