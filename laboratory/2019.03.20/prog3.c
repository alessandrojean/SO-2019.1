/*
 * Alterando o tamanho do segmento de dados
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <unistd.h>

char str_dados[10];

int main() {
  char str_pilha[10], *topo;
  int pagesize = getpagesize();

  printf("Tamanho em bytes de um endereço: %lu\n", sizeof(char*));
  printf("Tamanho em bytes de uma página: %d\n", pagesize);

  printf("str_pilha  = %p\n", str_pilha);
  printf("main       = %p\n", main);
  printf("str_dados  = %p\n", str_dados);

  /* Verifica o endereço da borda da área de dados */
  topo = sbrk(0);
  printf("Topo da área de dados = %p\n", topo);

  /* Aumenta a área de dados em uma página */
  if (sbrk(pagesize) == (void*)-1)
    printf("Não foi possível alterar o segmento de dados\n");

  /* Verifica o novo endereço da borda da área de dados */
  topo = sbrk(0);
  printf("Topo da área de dados = %p\n", topo);

  /* Acarretaria SEGMENTATION_FAULT */
  // *topo = 'c';

  /* Aumenta a área de dados em menos de uma página,
     mas uma página na prática */
  if (sbrk(1024) == (void*)-1)
    printf("Não foi possível alterar o segmento de dados\n");

  /* Verifica o novo endereço da borda da área de dados (na teoria) */
  topo = sbrk(0);
  printf("Topo da área de dados = %p\n", topo);

  /* Não acarreta SEGMENTATION_FAULT */
  *topo = 'c';

  return 0;
}
