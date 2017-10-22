#include <stdio.h>
#include <stdlib.h>

typedef struct aluno{
    char nome[80];
    double nota;
}aluno;

aluno le_aluno(void){
    aluno a;
    printf("Digite o nome do aluno: ");
    scanf("%79[^\n]%*c",a.nome);
    printf("Digite a nota do aluno: ");
    scanf("%lf%*c",&a.nota);
    return a;
}

void imprime_aluno(aluno a){
    printf("Nome do aluno: %s\n",a.nome);
    printf("Nota do aluno: %lf\n",a.nota );
}

void listar_turma(aluno turma[],int n){
    int i;
    for(i=0;i<n;i++){
        imprime_aluno(turma[i]);
    }
}
int main(void){
    aluno* turma;
    int i,n;
    printf("Digite o número de alunos: ");
    scanf("%d%*c",&n);
    turma =  malloc(n * sizeof(aluno));
    for(i=0;i<n;i++){
        turma[i] = le_aluno();
    }
    listar_turma(turma, n);
    return 0;
}
