#include <stdio.h>

// Função de Ackermman
// https://en.wikipedia.org/wiki/Ackermann_function
int ack(int m,int n){
    if(m == 0){
        return n+1;
    }
    if(m > 0 &&  n == 0){
        return ack(m-1,1);
    }
    return ack(m-1,ack(m,n-1));
}

int main(void){
    printf("Ack(2,3) = %d.\n", ack(2,3));
    printf("Ack(1,3) = %d.\n", ack(1,3));
    printf("Ack(2,2) = %d.\n", ack(2,2));
    printf("Ack(5,4) = %d.\n", ack(5,4)); // Stack Overflow
    return 0;
}
