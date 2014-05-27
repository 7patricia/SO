#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "bib.c"

#define SIZE 32
#define PIPE_NAME "/tmp/server"

int main(int argc, char **argv) {
  int fd = open(PIPE_NAME, O_WRONLY);
  char buf[SIZE];

  while (1) {
    printf("Mensagem a enviar para o servidor: ");
    gets(buf);
    write(fd, buf, SIZE);
  }
}
