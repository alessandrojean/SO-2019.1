/*
 * Produtor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

typedef struct {
  long type;
  char content[100];
} message;

#define N 10
#define MAILBOX_PC 453
#define MAILBOX_CP 454

int main(int argc, char** argv) {
  int flag, msgflg, msqidpc, msqidcp;
  message mpc, mcp;

  // Cria estrutura de mensagem
  msqidpc = msgget(MAILBOX_PC, 0666 | IPC_CREAT);
  if (msqidpc <= 0) {
    perror("Erro na criacao de mailbox pc");
  }

  msqidcp = msgget(MAILBOX_CP, 0666 | IPC_CREAT);
  if (msqidcp <= 0) {
    perror("Erro na criacao de mailbox cp");
  }

  for (int i = 0; i < N; i++) {
    // Recebe mensagem
    msgflg = MSG_NOERROR;
    flag = msgrcv(msqidcp, &mcp, 100, 0, msgflg);

    if (flag >= 0) {
      printf("Recebido mensagem do consumidor\n");
    } else {
      perror("Erro na recepcao cp");
    }

    // Preenche estrutura de mensagem
    mpc.type = 1;
    sprintf(mpc.content, "Esta eh a mensagem de teste %d", i);

    // Envia
    flag = msgsnd(msqidpc, &mpc, strlen(mpc.content) + 1, 0);
    printf("O resultado eh: %d\n", flag);
  }

  return EXIT_SUCCESS;
}
