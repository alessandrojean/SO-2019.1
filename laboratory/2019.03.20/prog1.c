/*
 * Qual abordagem para alocação?
 */

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *s1, *s2, *s3, *s4, *s5, *s6;
  printf("Size of int: %lu bytes\n", sizeof(int));
  s1 = (int *)malloc(sizeof(int) * 100);
  printf("Aloca s1: %p\n", (void *)s1);
  s2 = (int *)malloc(sizeof(int) * 50);
  printf("Aloca s2: %p\n", (void *)s2);
  s3 = (int *)malloc(sizeof(int) * 60);
  printf("Aloca s3: %p\n", (void *)s3);
  s4 = (int *)malloc(sizeof(int) * 100);
  printf("Aloca s4: %p\n", (void *)s4);
  free(s1);
  free(s3);
  printf("Libera s1.\n");
  printf("Libera s3.\n");

  s5 = (int *)malloc(sizeof(int) * 2);
  printf("Aloca s5: %p\n", (void *)s5);

  s6 = (int *)malloc(sizeof(int) * 50);
  printf("Aloca s6: %p\n", (void *)s6);

  return 0;
}
