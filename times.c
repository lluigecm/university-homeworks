#include <stdio.h>
#include <stdlib.h>

void main (){

    int qnt_clubes;
    char **time;

    do{
        printf("Quantos times vao jogar? ");
        scanf(" %d", &qnt_clubes);
    }while(qnt_clubes<2);

    time = (char*) malloc(qnt_clubes*sizeof(char*));
    
    for(int i = 0; i<qnt_clubes;i++){
        time[i] = (char*) malloc(30*sizeof(char*));
    }

    for(int i = 0; i<qnt_clubes;i++){
        printf("Qual o nome do time %d? ", i+1);
        scanf(" %s", &*time[i]);
    }

    printf("\n----------------Tabela de jogos---------------------\n");

    for(int i = 0; i < (qnt_clubes - 1);i++){
        printf("\n");
        for(int j = i + 1; j< qnt_clubes; j++){
            printf("\t%s x %s", time[i], time[j]);
        }
    }

    for(int i = 0; i < qnt_clubes;i++){
        free(time[i]);
    }
    free(time);
}

// Aluno: Lucas Luige Costa Miranda  202220035