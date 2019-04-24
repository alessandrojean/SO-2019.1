#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char** argv) {
  int pid;
  int status;

  // Chamada de sistema fork
  pid = fork();

  if (pid == 0) {
    // Filho
    // Operação não permitida
    // Divisão por zero.
    int x = 2 / 0;
    printf("Filho terminando a execução.\n");
  } else {
    // Pai
    printf("Pai com filho com PID %d.\n", pid);
    printf("Aguardando término do filho!\n");

    int p = waitpid(pid, &status, 0);
    printf("Pai viu filho com PID %d terminar.\n", p);

    if (WIFEXITED(status)) {
      printf("Filho terminou com status = %d.\n", WEXITSTATUS(status));
    } else if (WIFSIGNALED(status)) {
      printf("Filho foi morto por sinal %d.\n", WTERMSIG(status));
    }

    printf("Pai terminando a execução.\n");
  }

  return EXIT_SUCCESS;
}
