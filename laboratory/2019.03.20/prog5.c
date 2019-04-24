#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>

#define NULL 0

int main() {
  int fd;
  char* s;

  fd = open("teste_mmap.txt", O_RDWR);

  s = mmap(NULL, 100, PROT_WRITE, MAP_SHARED, fd, 0);

  s[2] = 'z';

  munmap(s, 100);

  return 0;
}
