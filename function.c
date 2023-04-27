#include <stdio.h>
struct data teste (struct data x);

struct data{
        int dia;
        int ano;   //deixei a struct fora da main para ser considerada global pelo sistema.
        int mes;
};

void main() 
{
    struct data hoje;
    hoje.dia=04;
    hoje.mes=04;
    hoje.ano=2024;

    printf("dia %d\t", hoje.dia);
    printf("mes %d\t", hoje.mes);
    printf("ano %d\t\n", hoje.ano);


    struct data proxima; //criei nova estrutura do mesmo tipo
    proxima = teste(hoje); // joguei os valores gerados pela função teste, na nova estrutura
    
    printf("dia %d\t", proxima.dia);
    printf("mes %d\t", proxima.mes);
    printf("ano %d", proxima.ano);

}

struct data teste (struct data x){
    x.dia=100;          // função teste que modifica os valores da struct apontada
    x.ano=10000;
    x.mes=20049;

    return x;
}
