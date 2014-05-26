#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define SIZE 32
#define PIPE_NAME "/tmp/server"

int main(int argc, char **argv) {
  mkfifo(PIPE_NAME, 0666);
  char buf[SIZE];
  char *comando;
  char **args;
  int num, i=0;

  int fd = open(PIPE_NAME, O_RDONLY);

  Arvore *contadores;

  while (1) {
    // 1. ler o comando
    read(fd, buf, SIZE);
    comando = strtok(buf," ");
    args[i] = strtok(NULL,buf);

  while(!(isNumber(args[i])))
  {
    i++;
    args[i] = strtok(NULL,buf);
  }

  num = atoi(args[i]); 

    if (strcmp(comando,"incrementar")) {
      incrementar(args, num);
      gravar_as_cenas_em_ficheiro();
    }
    else if (strcmp(comando,"agregar")) {
      if fork() {
        agregar(args, num, "/tmp/cserver");
      }
    }


    printf("Received: %s\n", buf);
  }
}