#include <stdio.h>
#include <string.h>

int period(char str[]){
    int period = 0;
    int p;
    for(p=1;p<strlen(str);p++){
        int is_periodic = 1;
        int i;
        for(i=0;i<strlen(str)-p;i++){
            if(str[i]!=str[i+p]){
                is_periodic = 0;
            }
        }
        if(is_periodic){
            period = p;
        }
    }
    return period;
}

int main(void){
    char str[50];
    scanf("%s",str);
    int rv = period(str);
    printf("O periodo de %s e %d\n",str,rv);
    return 0;
}