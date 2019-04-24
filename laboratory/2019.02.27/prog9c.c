/*
 * Consumidor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>

typedef struct {
  long type;
  char content[100];
} message;

#define MAILBOX 453

int main(int argc, char** argv) {
  int flag, msgflg, msqid;
  message m;

  // Cria estrutura de mensagem
  msqid = msgget(MAILBOX, 0666 | IPC_CREAT);
  if (msqid <= 0) {
    perror("Erro na criacao de mailbox");
  }

  // Recebe mensagem
  msgflg = MSG_NOERROR;
  flag = msgrcv(msqid, &m, 100, 0, msgflg);

  if (flag >= 0) {
    printf("o tipo da mensagem eh: %ld\n", m.type);
    printf("o conteudo da mensagem eh: %s\n", m.content);
  } else {
    perror("erro na recepcao");
  }

  return EXIT_SUCCESS;
}
