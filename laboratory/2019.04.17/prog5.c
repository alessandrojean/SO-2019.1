#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>
#define ENUF(mensagem, valor) \
  { perror(mensagem); }

main(int argc, char *argv[]) {
  // Definição da estrutura do Inode.
  struct stat statbuf; 
  char s[127];

  if (argc != 2) {
    sprintf(s, "Uso: %s <nome do arquivo>", argv[0]);
    ENUF(s, 1);
  }

  if (stat(argv[1], &statbuf) == 1) {
    sprintf(s, "Nao e' possivel obter status de %s", argv[1]);
    ENUF(s, 2);
  }

  fprintf(stdout, "\n%s e' um ", argv[1]);
  switch (statbuf.st_mode & S_IFMT) {
    case S_IFREG:
      fprintf(stdout, "arquivo regular \n");
      break;
    case S_IFDIR:
      fprintf(stdout, "arquivodiretorio \n");
      break;
    case S_IFCHR:
      fprintf(stdout, "arquivo especial (caracter) \n");
      break;
    case S_IFBLK:
      fprintf(stdout, "arquivo especial (bloco) \n");
      break;
  }
  
  fprintf(stdout, "\nuserid %d, ", statbuf.st_uid);
  fprintf(stdout, "groupid %d, ", statbuf.st_gid);
  fprintf(stdout, "permissao %o, ", statbuf.st_mode);
  fprintf(stdout, "link(s) %d \n", statbuf.st_nlink);
  fprintf(stdout, "tamanho %d (bytes)", statbuf.st_size);
  fprintf(stdout, ", %d (blocos), ", statbuf.st_blocks);
  fprintf(stdout, "Inode # %d \n\n", statbuf.st_ino);
  fprintf(stdout, "Dados de %s foram modificados pela ultima vez em %s",
          argv[1], ctime(&statbuf.st_mtime));
  fprintf(stdout, "\nLeitura ");
  fprintf(stdout, (access(argv[1], R_OK) == 0) ? "permitida\n" : "proibida\n");
  fprintf(stdout, "Escrita ");
  fprintf(stdout, (access(argv[1], W_OK) == 0) ? "permitida\n" : "proibida\n");
  fprintf(stdout, "Execucao ");
  fprintf(stdout,
          (access(argv[1], X_OK) == 0) ? "permitida\n" : "proibida\n\n");
}
