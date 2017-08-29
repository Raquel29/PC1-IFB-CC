#include <stdio.h>
#include <math.h>

int main(void){
    int opcao;
    double x,y;
    double resultado;
    do{
        printf("Menu\n");
        printf("1 - Adição\n");
        printf("2 - Subtração\n");
        printf("3 - Multiplicação\n");
        printf("4 - Divisão\n");
        printf("5 - Potenciação\n");
        printf("6 - Sair\n");
        printf("Digite a opção desejada [1-6]: ");
        scanf("%d",&opcao);
        if(opcao!=6){
            printf("Digite o valor do primeiro operando: ");
            scanf("%lf",&x);
            printf("Digite o valor do segundo operando: ");
            scanf("%lf",&y);

            switch(opcao){
                case 1:
                    resultado = x+y;
                    break;
                case 2:
                    resultado = x-y;
                    break;
                case 3:
                    resultado = x*y;
                    break;
                case 4:
                    resultado = x/y;
                    break;
                case 5:
                    resultado = pow(x,y);
                    break;
            }
            printf("O resultado da operação é: %lf\n",resultado);
        }
    } while(opcao !=6);
    return 0;
}
