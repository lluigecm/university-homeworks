#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int pnt = 0;

  do
  {
    pnt = pnt + rand() % 8;
    printf("Sua pontuacao e: %d\n", pnt);
  }while(pnt < 21);

  if( pnt == 21)
    printf("Voce ganhou!!!\n");
  else
    printf("Voce perdeu!!!\n");

  return 0;
}