#include <stdio.h>

int main(void){
    int qtd_notas = 0;
    int valor, valor_ori;
    printf("Digite o valor da quantia a ser paga: ");
    scanf("%d",&valor);
    valor_ori = valor;
    while(valor>=100){
        valor-=100;
        qtd_notas++;
    }
    while(valor>=50){
        valor-=50;
        qtd_notas++;
    }
    while(valor>=20){
        valor-=20;
        qtd_notas++;
    }
    while(valor>=10){
        valor-=10;
        qtd_notas++;
    }
    while(valor>=5){
        valor-=5;
        qtd_notas++;
    }
    while(valor>=2){
        valor-=2;
        qtd_notas++;
    }
    while(valor){
        valor--;
        qtd_notas++;
    }
    printf("São necessárias no mínimo %d notas para pagar %d reais.\n",qtd_notas,valor_ori);
    return 0;
}
