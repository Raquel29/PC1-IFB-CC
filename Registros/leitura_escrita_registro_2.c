#include <stdio.h>
#include <stdlib.h>

struct aluno{
    char nome[80];
    double nota;
};

struct aluno le_aluno(void){
    struct aluno a;
    printf("Digite o nome do aluno: ");
    scanf("%79[^\n]%*c",a.nome);
    printf("Digite a nota do aluno: ");
    scanf("%lf%*c",&a.nota);
    return a;
}

void imprime_aluno(struct aluno a){
    printf("Nome do aluno: %s\n",a.nome);
    printf("Nota do aluno: %lf\n",a.nota );
}

void listar_turma(struct aluno turma[],int n){
    int i;
    for(i=0;i<n;i++){
        imprime_aluno(turma[i]);
    }
}
int main(void){
    struct aluno turma[5];
    int i;
    for(i=0;i<5;i++){
        turma[i] = le_aluno();
    }
    listar_turma(turma, 5);
    return 0;
}
