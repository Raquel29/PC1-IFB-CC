#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct aluno_t{
    char nome[30];
    int semestre;
    double ra;
} aluno_t;

int le_aluno(FILE* arq,aluno_t* aluno){
    char linha[80];
    if(!fgets(linha,80,arq)){
        return 0;
    }
    strncpy(aluno->nome,linha,30);
    fgets(linha,80,arq);
    aluno->semestre = atoi(linha);
    fgets(linha,80,arq);
    aluno->ra = atof(linha);
    return 1;
}

void processar_alunos(FILE* arq, int x){
    aluno_t aluno;
    while(le_aluno(arq,&aluno)){
        if(aluno.semestre == x){
            printf("Nome do aluno: %s",aluno.nome);
            printf("Semestre do aluno: %d\n",aluno.semestre);
            printf("Rendimento acadêmico do aluno: %lf\n\n",aluno.ra);
        }
    }
}

int main(int argc, char** argv){
    FILE* arq;
    int x;
    if(argc!=2){
        printf("Erro.\nUso: ./<nome do executavel> <arquivo>");
        return 0;
    }
    arq = fopen(argv[1],"r");
    printf("Digite o semestre que você quer pesquisar os alunos: ");
    scanf("%d",&x);
    processar_alunos(arq,x);
    return 0;
}
