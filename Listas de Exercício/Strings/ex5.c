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

int main(void){
    char str[80];
    printf("Digite sua string: ");
    scanf("%79[^\n]%*c",str);
    reverse(str);
    printf("String invertida: %s.\n",str);
    return 0;
}
