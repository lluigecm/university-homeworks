#include <stdio.h>
#include <stdlib.h>

void main ()
{

    struct aluno{
        char nome[30];      // definição de uma estrutura
        char materia[30];
        int nota[3]
    };

    struct aluno prod;  //declaração de uma variavel do tipo aluno, que e uma struct

    printf("Insira o nome do aluno: ");
    scanf("%s", &prod.nome);
    printf("Qual a materia? ");
    scanf("%s", &prod.materia);

    for(int i = 0; i < 3; i++){
        printf("insira a nota da prova %d: ", i+1);
        scanf(" %d", &prod.nota[i]);
    }
    
    printf("\n\n-----------------Analise de aluno--------------------------\n");
    printf("Nome:\t\t%s\n", prod.nome);
    printf("Materia:\t%s\n", prod.materia);
    printf("Nnta pr1:\t%d\nNnta pr2:\t%d\nNnta pr3:\t%d\n", prod.nota[0], prod.nota[1], prod.nota[2]);
    printf("-----------------------------------------------------------");
    
}