#include <stdio.h>
int nro_bits(int n);
int nro_bits_rec(int n);

int nro_bits(int n){
    return n == 0 ?  1 :  nro_bits_rec(n);
}
int nro_bits_rec(int n){
    return n == 0 ? 0 : 1 + nro_bits_rec(n>>1);
}

int main(void){
    int n;
    printf("Digite o nro: ");
    scanf("%d",&n);
    printf("%d precisa de %d bits.\n",n,nro_bits(n));
    return 0;
}
