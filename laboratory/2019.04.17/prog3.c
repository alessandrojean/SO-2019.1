#include <fcntl.h>

main() {
  int arquivo = open("testeNoSync.txt", O_RDWR | O_CREAT, 0777);

  int i = 0;
  while (i < 1000) {
    write(arquivo, "0", 1);
    i++;
  }

  close(arquivo);
}
