#include <stdio.h>
#include <stdlib.h>

struct aluno{
    char nome[45];
    double nota;
};

int main(void){
    struct aluno a,b;
    printf("Digite o nome do primeiro aluno: ");
    scanf("%44[^\n]%*c",a.nome);
    printf("Digite a nota do primeiro aluno: ");
    scanf("%lf%*c",&a.nota);

    printf("Digite o nome do segundo aluno: ");
    scanf("%44[^\n]%*c",b.nome);
    printf("Digite a nota do segundo aluno: ");
    scanf("%lf%*c",&b.nota);

    printf("Nome do primeiro aluno: %s\n",a.nome);
    printf("Nota do primeiro aluno: %lf\n",a.nota );

    printf("Nome do segundo aluno: %s\n",b.nome);
    printf("Nota do segundo aluno: %lf\n",b.nota );

    printf("Copiando os dados do primeiro para o segundo.\n");
    b = a;

    printf("Nome do segundo aluno: %s\n",b.nome);
    printf("Nota do segundo aluno: %lf\n",b.nota );
    
    return 0;
}
