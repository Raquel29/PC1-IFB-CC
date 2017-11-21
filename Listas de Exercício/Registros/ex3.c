#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct ponto_t{
    double x,y;
}ponto_t;

typedef struct poligono_t{
    ponto_t* p;
    int n_lados;
}poligono_t;

void le_poligono(poligono_t* polig){
    int i;
    printf("Digite o nro de lados: ");
    scanf("%d",& polig->n_lados);
    polig->p = calloc(polig-> n_lados, sizeof(ponto_t));
    if(polig->p!=NULL){
        printf("Erro ao alocar memoria.\n");
        exit(EXIT_FAILURE);
    }
    for(i=0;i<polig->n_lados;i++){
        printf("Digite o %d vertice do poligono: ",i+1);
        scanf("%lf", &(polig->p[i].x));
        scanf("%lf", &(polig->p[i].y));
    }
}

double dist(ponto_t a,ponto_t b){
    return (sqrt(pow(a.x-b.x,2) + pow(a.y-b.y,2) ));
}
double perimetro(poligono_t polig){
    int i;
    double soma = 0;
    for(i=0;i<polig.n_lados;i++){
        soma += dist(polig.p[i],polig.p[(i+1)%polig.n_lados]);
    }
    return soma;
}

double det(ponto_t a,ponto_t b){
    return a.x*b.y - a.y*b.x;
}

double area(poligono_t polig){
    double area = 0;
    int i;
    for(i=0;i<polig.n_lados;i++){
        area += det(polig.p[i],polig.p[(i+1) % polig.n_lados]);
    }
    return fabs(area/2.0);
}
int main(void){
    poligono_t polig;
    le_poligono(&polig);
    printf("Perimetro: %lf\n",perimetro(polig));
    printf("Area: %lf\n",area(polig));
}
