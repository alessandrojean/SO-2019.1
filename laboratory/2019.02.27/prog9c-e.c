/*
 * Consumidor.
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
    perror("Erro na criacao de mailbox pc");
  }

  for (int i = 0; i < N; i++) {
    // Preenche estrutura de mensagem
    mcp.type = 1;
    strcpy(mcp.content, "\0");

    msgsnd(msqidcp, &mcp, strlen(mcp.content) + 1, 0);
  }

  for (int i = 0; i < N; i++) {
    // Recebe mensagem
    msgflg = MSG_NOERROR;
    flag = msgrcv(msqidpc, &mpc, 100, 0, msgflg);

    if (flag >= 0) {
      printf("O tipo da mensagem %d eh: %ld\n", i, mpc.type);
      printf("O conteudo da mensagem %d eh: %s\n", i, mpc.content);
    } else {
      perror("Erro na recepcao pc");
    }
  }

  return EXIT_SUCCESS;
}
