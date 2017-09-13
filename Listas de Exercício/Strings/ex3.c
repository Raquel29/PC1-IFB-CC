#include <stdio.h>
#include <string.h>

int my_strcmp(char str1[],char str2[]){
    int i;
    for(i=0; str1[i]==str2[i] && i<strlen(str1) && i<strlen(str2); i++);
    return str1[i]-str2[i];
}

int main(void){
    char str1[80];
    char str2[80];
    printf("Digite a primeira string: ");
    scanf("%79[^\n]%*c",str1);
    printf("Digite a segunda string: ");
    scanf("%79[^\n]%*c",str2);
    int retorno = my_strcmp(str1,str2);
    if(retorno<0){
        printf("%s é lexicograficamente menor que %s.\n",str1,str2);
    }
    else if(retorno == 0){
        printf("%s é igual a %s.\n",str1,str2);
    }
    else{
        printf("%s é lexicograficamente maior que %s.\n",str1,str2);
    }
    return 0;
}
