/*
 * Teste simples para leitura de diretórios.
 */
#include <dirent.h>
#include <stdio.h>
#include <sys/types.h>

int main(int argc, char **argv) {
  DIR *d;
  struct dirent *ep;

  if (argc == 1) {
    printf("%s <dir>\n", argv[0]);
    return 0;
  }

  if ((d = opendir(argv[1])) == NULL) {
    perror("opendir");
    return 0;
  }

  while ((ep = readdir(d)))
    printf("%s (Inode %d)\n", ep->d_name, (int)ep->d_ino);

  closedir(d);

  return 0;
}
