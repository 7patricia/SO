#include <string.h>

struct args_incrementar {
  int valor;
  char nomes[3][20];
};

struct args_agregar {
  int nivel;
  char ficheiro[50];
  char nomes[3][20];
};

struct args_incrementar parse_args_incrementar() {
  struct args_incrementar args;
  strcpy(args.nomes[0], "");
  strcpy(args.nomes[1], "");
  strcpy(args.nomes[2], "Sem freguesia");

  // TODO garantir que ha pelo menos 2

  char* valor_string = strtok(NULL, " ");
  args.valor = atoi(valor_string);

  int i = 0;
  char*token;
  token = strtok(NULL, " ");
  while(token != NULL)  {
    strcpy(args.nomes[i], token);
    i++;
    token = strtok(NULL, " ");
  }

  printf("incrementar: %d em %s %s %s", args.valor, args.nomes[0], args.nomes[1], args.nomes[2]);
  return args;
}


struct args_agregar parse_args_agregar() {
  struct args_agregar args;
  strcpy(args.nomes[0], "");
  strcpy(args.nomes[1], "");
  strcpy(args.nomes[2], "Sem freguesia");

  // TODO garantir que ha pelo menos 2

  char* nivel_string = strtok(NULL, " ");
  args.nivel = atoi(nivel_string);

  char ficheiro[50];
  strcpy(args.ficheiro, strtok(NULL, " "));

  int i = 0;
  char *token;
  token = strtok(NULL, " ");
  while(token != NULL)  {
    strcpy(args.nomes[i], token);
    i++;
    token = strtok(NULL, " ");
  }

  printf("agregar: nivel %d no ficheiro %s as cidades %s %s %s", args.nivel, args.ficheiro, args.nomes[0], args.nomes[1], args.nomes[2]);
  return args;
}

struct array_distritos {
  struct distrito ;
}

struct freguesia {
  char nome[20];
  int valor;
};

struct concelho {
  char nome[20];
  struct freguesia_s *freguesias;
};

struct distrito {
  char nome[20];
  struct concelho_s *concelhos;
};

int incrementar(char *nome[], unsigned valor) {

        // TODO 2.procurar o conselho (criar se nao existir)
        // TODO 3.procurar a freguesia (criar se nao existir)
        //
        // TODO 4.incrementar o valor
  return 0;
}
int agregar(char *prefixo[], unsigned nivel, char *path) {
    // TODO 5. nivel == 0 ..
        // TODO 5. nivel == 1 ..
        // TODO 5. nivel == 2 ..
        // TODO 5. nivel == 3 ..
        //
        // TODO muitos. gravar no ficheiro
  return 0;
}

//Função que procura um distrito e se não existir cria um novo

struct distrito procura_distrito(struct array_distritos distritos, char *nome)
{
  int i;

  for(i=0;i<distritos.num;i++)
    if(strcmp(nome,distritos.distritos[i]->nome)==0)
      return distritos.distritos[i];
  struct distrito novo_distrito = (struct distrito)malloc(sizeof(struct distrito));
  novo_distrito.nome = nome;

  return novo_distrito;
}

