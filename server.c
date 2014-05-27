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

      incrementar(args_incrementar.nomes, args_incrementar.valor);
        // TODO 1.procurar o distrito (criar se nao existir)
        // TODO 2.procurar o conselho (criar se nao existir)
        // TODO 3.procurar a freguesia (criar se nao existir)
        //
        // TODO 4.incrementar o valor
    } else if (strcmp(comando, "agregar") == 0) {
      struct args_agregar args_ag = parse_args_agregar();

      agregar(args_agregar.nomes, args_agregar.nivel, args_agregar.ficheiro);
        // TODO 5. nivel == 0 ..
        // TODO 5. nivel == 1 ..
        // TODO 5. nivel == 2 ..
        // TODO 5. nivel == 3 ..
        //
        // TODO muitos. gravar no ficheiro
    }
  }
}
