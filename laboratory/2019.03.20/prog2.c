#include <math.h>
#include <stdio.h>
#include <unistd.h>

int global;

int main() {
  int pagesize, bits_pagina, address_bits;

  pagesize = getpagesize();
  bits_pagina = log2(pagesize);
  address_bits = 8 * sizeof(char*);

  printf("Endereço de global: %p\n", &global);
  printf("Tamanho de uma página 0x%x, %d bits\n", pagesize, bits_pagina);
  printf("Endereço: %lu bytes, %d bits\n", sizeof(char*), address_bits);

  return 0;
}
