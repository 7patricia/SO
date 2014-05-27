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
  char *args[20];
  int i=0;

  int fd = open(PIPE_NAME, O_RDONLY);

  // Arvore *contadores;

  while (1) {
    i = 0;
    // 1. ler o comando
    read(0, buf, SIZE);
    comando = strtok(buf," ");
    char*token;
    while((token = strtok(NULL, " "))!=NULL)  {
      printf("token:%s",token);
      strcpy(args[i], token);
      i++;
    }

    int valor = atoi(token[i-1]);
    int num_tokens = i-2;

    int j;
    for(j=0;j<num_tokens;j++){
      printf("%s\n",args[j]);
    }

    // if (strcmp(comando,"incrementar")) {
    //   incrementar(args, valor);
    //   gravar_as_cenas_em_ficheiro();
    // }
    // else if (strcmp(comando,"agregar")) {
    //   if fork() {
    //     agregar(args, valor, "/tmp/server");
    //   }
    // }
  }
}