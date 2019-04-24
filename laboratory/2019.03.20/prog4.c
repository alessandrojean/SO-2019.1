/*
 * Exemplo com mmap.
 */

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#define MSIZE 100

int main() {
  int fd;
  char* s;

  if ((fd = open("teste_mmap.txt", O_CREAT | O_RDWR), 0600) == -1) {
    perror("open");
    exit(1);
  }
  ftruncate(fd, MSIZE);

  /* MAP_SHARED

     Share this mapping with all other processes that map this object.
     Storing to the region is equivalent to writing to the file.  The
     file may not actually be updated until msync(2) or munmap(2) are
     called. */

  if ((s = mmap(NULL, MSIZE, PROT_WRITE, MAP_SHARED, fd, 0)) == (void*)-1) {
    perror("mmap");
    exit(1);
  }

  sprintf(s, "Testando mmap.\n");

  /* The flags argument may have the bits MS_ASYNC, MS_SYNC and
     MS_INVALIDATE set, but not both MS_ASYNC and MS_SYNC.  MS_ASYNC
     specifies that an update be scheduled, but the call returns
     immediately.  MS_SYNC asks for an update and waits for it to
     complete.  MS_INVALIDATE asks to invalidate other mappings of the
     same file (so that they can be updated with the fresh values just
     written). */

  if (msync(s, MSIZE, MS_SYNC) == -1) perror("msync");

  sprintf(s, "Testando mmap novamente.\n");

  munmap(s, MSIZE);

  close(fd);

  return 0;
}
