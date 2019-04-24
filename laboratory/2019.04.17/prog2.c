#include <fcntl.h>
#include <stdio.h>
#include <string.h>

int main() {
  int tmp = open("temp.txt", O_CREAT | O_RDWR | O_TRUNC, 00777);
  while (1) {
    printf(
        "Digite unlink para chamada unlink, print para imprimir conteúdo e "
        "quit para encerrar o programa: ");
    char buf[255];
    scanf("%s", buf);
    if (strcmp(buf, "unlink") == 0) {  
      // Comando unlink.
      printf("Unlink executado apos comando: %s \n", buf);
      unlink("temp.txt");
    } else if (strcmp(buf, "quit") == 0) {  
      // Comando quit.
      return 0;
    } else if (strcmp(buf, "print") == 0) {  
      // Comando print.
      lseek(tmp, 0);
      char c;
      while ((read(tmp, &c, 1)) > 0) {
        printf("%c", c);
      }
    } else {  
      // Demais - grava no temp.txt e volta o loop.
      write(tmp, buf, strlen(buf));
      write(tmp, "\n", 1);
      printf("Grava e retorna ao loop apos comando: %s \n", buf);
    }
  }
}
