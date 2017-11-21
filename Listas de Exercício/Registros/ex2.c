#include <stdio.h>

typedef struct complex_t{
    double r;
    double im;
}complex_t;

complex_t soma(complex_t a,complex_t b){
    complex_t c;
    c.r = a.r + b.r;
    c.im = a.im + b.im;
    return c;
}

complex_t subtracao(complex_t a,complex_t b){
    complex_t c;
    c.r = a.r - b.r;
    c.im = a.im - b.im;
    return c;
}

complex_t multiplicacao(complex_t a,complex_t b){
    complex_t c;
    c.r = a.r * b.r - a.im * b.im;
    c.im = a.r * b.im +  b.r*a.im;
    return c;
}

complex_t divisao(complex_t a, complex_t b){
    complex_t num,denom;
    complex_t c;
    complex_t conjugado;
    conjugado.r = b.r;
    conjugado.im = -b.im;
    num  = multiplicacao(a,conjugado);
    denom = multiplicacao(b,conjugado);
    c.r = num.r/denom.r;
    c.im = num.im / denom.r;
    return c;
}

void le_complexo(complex_t* c){
    printf("Parte real: ");
    scanf("%lf",&c->r);
    printf("Parte imaginaria: ");
    scanf("%lf",&c->im);
}

void imprime_complexo(complex_t c){
    printf("Parte real: %lf\n",c.r);
    printf("Parte imaginaria: %lf\n",c.im);
}


int menu(void){
    int op;
    printf("1 - Somar dois numeros complexos.\n");
    printf("2 - Subtrair dois numeros complexos.\n");
    printf("3 - Multiplicar dois numeros complexos.\n");
    printf("4 - Dividir dois numeros complexos.\n");
    printf("5 - Sair\n");
    printf("Digite a sua opcao: ");
    scanf("%d",&op);
    return op;

}

int main(void){
    complex_t a,b;
    int opcao;
    do{
        opcao = menu();
        switch (opcao) {
            case 1:
                le_complexo(&a);
                le_complexo(&b);
                imprime_complexo(soma(a,b));
                break;
            case 2:
                le_complexo(&a);
                le_complexo(&b);
                imprime_complexo(subtracao(a,b));
                break;
            case 3:
                le_complexo(&a);
                le_complexo(&b);
                imprime_complexo(multiplicacao(a,b));
                break;
            case 4:
                le_complexo(&a);
                le_complexo(&b);
                imprime_complexo(divisao(a,b));
                break;
        }
    }while(opcao!=5);
}
