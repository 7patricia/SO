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

struct distrito {
  char nome[20];
  int pipe[2];
};

struct distritos {
  struct distrito array[100];
  int num_distritos;
};

/* struct freguesia { */
/*   char nome[20]; */
/*   int valor; */
/* }; */

/* struct concelho { */
/*   char nome[20]; */
/*   struct freguesia freguesias[100]; */
/*   int num_freguesias; */
/* }; */

void criar_distrito(struct distritos* distritos, char *nome);
void tratar_distrito(struct distrito* distrito);
struct distrito procura_distrito(struct distritos* distritos, char *nome);

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

  /* printf("incrementar: %d em %s %s %s", args.valor, args.nomes[0], args.nomes[1], args.nomes[2]); */
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

int incrementar(struct distritos distritos, char nome[3][20], unsigned valor) {
        // TODO 4.incrementar o valor
  printf("incrementar %s:%s:%s\n", nome[0], nome[1], nome[2]);

  struct distrito dist = procura_distrito(&distritos, nome[0]);

  int val = 2;
  printf("a enviar para %d:%d\n", dist.pipe[0], dist.pipe[1]);
  write(dist.pipe[1], &val, sizeof(int));

  return 0;
}

int agregar(char prefixo[3][20], unsigned nivel, char *path) {
    // TODO 5. nivel == 0 ..
        // TODO 5. nivel == 1 ..
        // TODO 5. nivel == 2 ..
        // TODO 5. nivel == 3 ..
        //
        // TODO muitos. gravar no ficheiro
  return 0;
}

//Função que procura um distrito e se não existir cria um novo

struct distrito procura_distrito(struct distritos* distritos, char *nome)
{
  int i=0;

  while (i < distritos->num_distritos) {
    if(strcmp(nome,distritos->array[i].nome)==0)
      return distritos->array[i];
    i++;
  }

  criar_distrito(distritos, nome);

  return distritos->array[i];
}

void criar_distrito(struct distritos* distritos, char *nome) {
  printf("a criar distrito\n");
  int i = distritos->num_distritos;
  struct distrito* distrito = &(distritos->array[i]);
  strcpy(distrito->nome, nome);
  distritos->num_distritos++;

  pipe(distrito->pipe);

  if (fork() == 0) {
    tratar_distrito(distrito);
  }
}

void tratar_distrito(struct distrito* distrito) {
  printf("%s\n", distrito->nome);

  while(1) {
    int val;
    printf("a receber de %d:%d\n", distrito->pipe[0], distrito->pipe[1]);
    read(distrito->pipe[0], &val, sizeof(int));
    printf("recebido: %d\n", val);
  }
}

  //Função que procura um concelho e se não existir cria um novo

/* struct concelho procura_concelho(struct concelho *concelhos, char *nome) { */

/*   int i=0; */

/*   while(concelhos[i]!=NULL) */
/*     if(strcmp(nome,concelhos->concelho[i].nome)==0) */
/*       return concelhos->concelho[i]; */
/*   struct concelho novo_concelho = (struct concelho)malloc(sizeof(struct concelho)); */
/*   novo_concelho.nome = nome; */

/*   return novo_concelho; */
/* } */

/* //Função que procura uma freguesia e se não existir cria um novo */

/* struct freguesia procura_freguesia(struct freguesia_s *freguesias, char *nome) { */

/*   int i=0; */

/*   while(freguesias[i]!=NULL) */
/*     if(strcmp(nome,freguesias->freguesia[i].nome)==0) */
/*       return freguesias->freguesia[i]; */
/*   struct freguesia nova_freguesia = (struct freguesia)malloc(sizeof(struct freguesia)); */
/*   nova_freguesia.nome = nome; */

/*   return nova_freguesia; */
/* } */

