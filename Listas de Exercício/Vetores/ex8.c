#include <stdio.h>
#include <limits.h>
#define MAX 1000


int main(void){
    int temp[MAX];
    int n;
    int i;
    double media;
    int maior_temp, dia_maior_temp;
    int menor_temp, dia_menor_temp;
    printf("Entre a quantidade de dias: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Entre a temperatuda do dia %d: ",i);
        scanf("%d",&temp[i]);
    }

    media = 0.0;
    for(i=0;i<n;i++){
        media += temp[i];
    }
    media /= n;

    menor_temp = INT_MAX;
    maior_temp = INT_MIN;
    for(i=0;i<n;i++){
        if(temp[i]<menor_temp){
            menor_temp = temp[i];
            dia_menor_temp = i;
        }
        if(temp[i]>maior_temp){
            maior_temp = temp[i];
            dia_maior_temp = i;
        }
    }

    printf("Menor temperatura = %d graus e ocorreu no dia %d\n",menor_temp,dia_menor_temp);
    printf("Maior temperatura = %d graus e ocorreu no dia %d\n",maior_temp,dia_maior_temp);
    printf("Temperatura media: %lf\n",media);
    printf("Dias em que a temperatura foi maior ou igual a media\n");
    for(i=0;i<n;i++){
        if(temp[i]>=media){
            printf("Dia %d\n",i);
        }
    }
    return 0;
}
