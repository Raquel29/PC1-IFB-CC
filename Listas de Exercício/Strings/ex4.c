#include <stdio.h>
#include <string.h>

int is_palindrome(char str[]){
    int i;
    int n = strlen(str);
    for(i=0;i<n/2;i++){
        if(str[i]!=str[n-i-1]){
            return 0;
        }
    }
    return 1;
}

int main(void){
    char str[80];
    printf("Digite sua string: ");
    scanf("%79[^\n]%*c",str);
    if(is_palindrome(str)){
        printf("%s é um palíndromo.\n",str);
    }
    else{
        printf("%s não é um palíndromo.\n",str);
    }
    return 0;
}
