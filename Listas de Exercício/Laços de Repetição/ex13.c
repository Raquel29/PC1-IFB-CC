#include <stdio.h>

int main(void){
    int qtd_notas_total;
    int qtd_notas_100;
    int qtd_notas_50;
    int qtd_notas_20;
    int qtd_notas_10;
    int qtd_notas_5;
    int qtd_notas_2;
    int qtd_notas_1;

    int valor, valor_ori;
    printf("Digite o valor da quantia a ser paga: ");
    scanf("%d",&valor);
    valor_ori = valor;

    qtd_notas_100 = valor/100;
    valor %= 100;

    qtd_notas_50 = valor/50;
    valor %= 50;

    qtd_notas_20 = valor/20;
    valor %= 20;

    qtd_notas_10 = valor/10;
    valor%=10;

    qtd_notas_5 = valor/5;
    valor %=5;

    qtd_notas_2 = valor/2;
    valor%=2;

    qtd_notas_1 = valor/1;

    qtd_notas_total = qtd_notas_100 + qtd_notas_50 + qtd_notas_20 + qtd_notas_10 + qtd_notas_5 + qtd_notas_2 + qtd_notas_1;

    printf("São necessárias no mínimo %d notas para pagar %d reais.\n",qtd_notas_total,valor_ori);
    printf("%d de 100.\n",qtd_notas_100);
    printf("%d de 50.\n",qtd_notas_50);
    printf("%d de 20.\n",qtd_notas_20);
    printf("%d de 10.\n",qtd_notas_10);
    printf("%d de 5.\n",qtd_notas_5);
    printf("%d de 2.\n",qtd_notas_2);
    printf("%d de 1.\n",qtd_notas_1);
    return 0;
}
