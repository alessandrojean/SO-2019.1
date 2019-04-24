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

#define MAILBOX 453

int main(int argc, char** argv) {
  int flag, msqid;
  message m;

  // Cria estrutura de mensagem
  msqid = msgget(MAILBOX, 0666 | IPC_CREAT);
  if (msqid <= 0) {
    perror("erro na criacao de mailbox");
  }

  // Preenche estrutura de mensagem
  m.type = 1;
  sprintf(m.content, "%s", "Esta eh uma mensagem de teste");

  // Envia
  flag = msgsnd(msqid, &m, strlen(m.content) + 1, 0);
  printf("o resultado eh: %d\n", flag);

  return EXIT_SUCCESS;
}
