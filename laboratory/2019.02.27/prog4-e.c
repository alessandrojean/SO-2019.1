#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void tratador_SIGSEGV(int signum) {
  printf("Tratando sinal SIGSEGV do processo %d!\n", getpid());
  exit(13);
  printf("Na verdade, acho que não vou fazer nada! :-) \n");
}

int main(int argc, char **argv) {
  int pid;
  int status;

  // Instalando tratador do sinal SIGINT
  signal(SIGSEGV, tratador_SIGSEGV);

  // Chamada de sistema fork
  pid = fork();

  if (pid == 0) {
    // Filho
    // Operação não permitida
    // Referencia a endereço de memória inválida
    int *px = (int *)0x01010101;
    *px = 0;

    printf("Filho (PID %d) vai dormir por 10 segundos.\n", getpid());
    sleep(10);
    printf("Filho terminando a execução.\n");
    return EXIT_SUCCESS;
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
