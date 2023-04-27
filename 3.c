#include <stdio.h>

int main(void)
{
    char ch;
    
    do
    {
        printf("Deseja continuar ( S ou s para sim, N ou n para nao)? ");
        scanf(" %c", &ch);
    }while(ch != 'N' && ch != 'n');

    return 0;
}