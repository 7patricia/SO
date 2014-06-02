#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define SIZE 32
#define PIPE_NAME "/tmp/server"

int main(int argc, char **argv) {
  int fd = open(PIPE_NAME, O_WRONLY);
  char buf[SIZE];

  while (1) {
    printf("Mensagem a enviar para o servidor: ");
    gets(buf);
    int size = strlen(buf);
    write(fd, &size, sizeof(int));
    write(fd, buf, size);
  }
}
