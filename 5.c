#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  int pnt = 0, pnt2 = 0, dist1, dist2;
  char resp = 1;

  do
  {
    pnt = pnt + rand() % 8;
    printf("Pontuacao atual do jogador 1 e: %d\n", pnt);
    printf("Deseja parar?s/n\n");
    scanf(" %c", &resp);
  } while (resp == 'N' || resp == 'n');

  do
  {
    pnt2 = pnt2 + rand() % 8;
    printf("Pontuacao atual do jogador 2 e: %d\n", pnt2);
    printf("Deseja parar?s/n\n");
    scanf(" %c", &resp);
  } while (resp == 'N' || resp == 'n');

  dist1 = 21 - pnt;
  dist1 = dist1 < 0 ? -dist1 : dist1;
  dist2 = 21 - pnt2;
  dist2 = dist2 < 0 ? -dist2 : dist2;

  if (dist1 < dist2)
    printf("Jogador 1 ganhou!!\n");
  else 
    if (dist2 < dist1)
      printf("Jogador 2 ganhou!!\n");
   else
      printf("Empate!!!");

  return 0;
}