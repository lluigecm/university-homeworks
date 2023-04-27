#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
void init_bibli();
void show_menu();
int choose();
void verif_option();
int verify_status(); 
void cad_livro();
void show_livros();
void get_livro();
void back_livro();
void clearBuffer();
void get_out();
void pause_continue();
#define lv_cad 3  //usei somente como uma base pra saber quantos livros mostrar disponiveis

struct library{
  int codigo;
  char nome[1][100];
  char autor[1][100];
  char status[1][100];
};

typedef struct library livro;
livro *book;
char resp;
int cod_liv;

void main(){
  init_bibli();
  show_menu();
}

void init_bibli(){
  printf("\t\t------ Bem vindo a biblioteca digital ------\n\n");
}

void show_menu(){

  printf("\t\t\t\t\t------ MENU ------\n\n");
  printf("[1] Cadastrar livro\n");
  printf("[2] Ver livros cadastrados\n");
  printf("[3] Pegar livro\n");
  printf("[4] Devolver livro\n");
  printf("[5] Sair\n");

  verif_option();

}

int choose(){ 
    int x;
    printf("\nQual opção deseja? ");
    scanf("%d", &x);  
    return x;
}

void verif_option(){
    switch (choose())
    {
    case 1:
        cad_livro();
    case 2:
        show_livros();
    case 3:
        get_livro();
    case 4:
        back_livro();
    case 5:
        get_out();
    default:
        get_out();
    }
}

void cad_livro(){
  int cont = 0;
  int qnt;
  printf("Quantos livros deseja cadastrar? ");
  scanf("%d", &qnt); 
  book = (livro*)malloc(sizeof(livro)*qnt); // Caso eu ja tivesse livros cadastrados, seria usado realloc (1inclusive, pensei na posssibilidade)
  do{
    printf("\nQual o codigo do livro %d? ", cont + 1);
    clearBuffer();
    scanf("%d", book[cont].codigo);
    printf("\nQual o nome do livro %d? ", cont + 1);
    clearBuffer();
    scanf("%s", book[cont].nome[0]);
    printf("\nQual o nome do autor do livro %d? ", cont + 1);
    clearBuffer();
    scanf("%s", book[cont].autor[0]);
    strcpy(book[cont].status[0], "disponivel");
    cont++;
  }while(cont < qnt);
  pause_continue();
  
}

void show_livros(){
    printf("\nOs livros abaixo se encontram disposniveis: \n");
     for(int i = 0; i < lv_cad; i++){
        //if(verify_status() == 1) deixei comentado pq n tem livros cadastrados, disponiveis ou emprestados. Portanto não precisa fazer verificação.
            printf("\n[%d] - Livro %d\n", i + 1, i + 1); 
     }
    pause_continue();
  //como é só um programa sem finalidade, não achei válido deixar livros cadastrados pra mostrar. Mas a intenção é mostrar todos os livros cadastrados que tem o status disponivel.  
}

void get_livro(){// dei preferencia a usar o codigo do livro para achá-lo na memoria, por ser de mais facil comparação
    printf("\nQual o codigo do livro que deseja pegar? ");
    clearBuffer();
    scanf("%d", &cod_liv);
    for(int i = 0; i < lv_cad; i++){
        if(book[i].codigo == cod_liv){
            strcpy(book[i].status[0], "emprestado");
            printf("\nVoce pegou o livro %s!!\n", book[i].nome[0]);
        }
    }
    cod_liv = NULL;
    pause_continue();
}

void back_livro(){
    printf("\nQual o codigo do livro que deseja devolver? ");
    clearBuffer();
    scanf("%d", &cod_liv);
    for(int i = 0; i < lv_cad; i++){
        if(book[i].codigo == cod_liv){
            strcpy(book[i].status[0], "disponivel");
            printf("\nVoce devolveu o livro %s\n!!", book[i].nome[0]);
        }
    }
    cod_liv = NULL;
    pause_continue();
}

int verify_status(){
    for(int i = 0; i < lv_cad; i++){
        if(book[i].status[0][0] == 'd'){//só preciso saber a primeira letra do status
            return 1;
        }else{
            return 0;
        }
    }

}

void pause_continue(){
    printf("\nDeseja realizar mais alguma ação? s/n ->  ");
    clearBuffer();
    scanf("%c", &resp);
    if(toupper(resp) =='S'){
        show_menu();
    }else{
        get_out();
    }
}

void clearBuffer(){// precisei criar essa função pq tava com problema no uso do scanf, e fflush não funcionava     
  while ( getchar() != '\n' );
}

void get_out(){
    printf("\n\n\t\tMuito obrigado por usar a plataforma, volte sempre!!");
    exit(1);
}