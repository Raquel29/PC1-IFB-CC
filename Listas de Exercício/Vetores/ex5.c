#include <stdio.h>
#include <math.h>
#include <float.h>
#define MAX 1000

int main(void){
    int n;
    double pontos_x[MAX];
    double pontos_y[MAX];
    int i,j;
    int ponto_a,ponto_b;
    double dist;
    printf("Digite o número de pontos: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Entre a abcissa do ponto %d: ",i+1);
        scanf("%lf",&pontos_x[i]);
        printf("Entre a ordenada do ponto %d: ",i+1);
        scanf("%lf",&pontos_y[i]);
    }

    dist = DBL_MAX;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            double distancia_local = sqrt( (pow(pontos_x[i]-pontos_x[j],2)) + (pow(pontos_y[i]-pontos_y[j],2)));
            if(distancia_local < dist){
                dist = distancia_local;
                ponto_a = i;
                ponto_b = j;
            }
        }
    }

    printf("A menor distância encontrada é %lf.\n",dist);
    printf("Os pontos envolvidos são (%lf,%lf) e (%lf,%lf).\n",pontos_x[ponto_a],pontos_y[ponto_a],pontos_x[ponto_b],pontos_y[ponto_b]);

    return 0;
}
