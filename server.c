#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 32
#define PIPE_NAME "/tmp/server"

#include "bib.h"

int main(int argc, char **argv) {
  mkfifo(PIPE_NAME, 0666);
  char buf[SIZE];
  char *comando;

  int fd = open(PIPE_NAME, O_RDONLY);

  while (1) {
    // 1. ler o comando
    int cmd_size;
    read(fd, &cmd_size, sizeof(int));
    read(fd, buf, cmd_size);
    buf[cmd_size]=+'\0';

    comando = strtok(buf," ");

    if (strcmp(comando, "incrementar") == 0) {
      struct args_incrementar args_inc = parse_args_incrementar();

      incrementar(args_inc.nomes, args_inc.valor);
        
    } else if (strcmp(comando, "agregar") == 0) {
      struct args_agregar args_ag = parse_args_agregar();

      agregar(args_ag.nomes, args_ag.nivel, args_ag.ficheiro);
      
    }
  }
}
