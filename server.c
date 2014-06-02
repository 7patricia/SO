#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 50
#define PIPE_NAME "/tmp/server"

#include "bib.h"

int main(int argc, char **argv) {
  mkfifo(PIPE_NAME, 0666);
  char buf[SIZE];
  char *comando;

  int fd = open(PIPE_NAME, O_RDONLY);

  struct distritos distritos;
  distritos.num_distritos = 0;

  while (1) {
    // 1. ler o comando
    int cmd_size;
    int bytes = read(fd, &cmd_size, sizeof(int));

    if (bytes > 0) {
      read(fd, buf, cmd_size);
      buf[cmd_size] = '\0';

      comando = strtok(buf," ");

      if (strcmp(comando, "incrementar") == 0) {
        struct args_incrementar args_inc = parse_args_incrementar();

        incrementar(distritos, args_inc.nomes, args_inc.valor);
      } else if (strcmp(comando, "agregar") == 0) {
        struct args_agregar args_ag = parse_args_agregar();

        agregar(args_ag.nomes, args_ag.nivel, args_ag.ficheiro);
      }
    } else {
      unlink(PIPE_NAME);
      mkfifo(PIPE_NAME, 0666);
      fd = open(PIPE_NAME, O_RDONLY);
    }
  }
}
