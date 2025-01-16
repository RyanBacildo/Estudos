#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[100];
  char telefone[15];
  char email[100];
} Contato;

int main() {
  FILE *arquivo;
  Contato contatos[500];

  // Gerar dados aleatórios para os contatos
  for (int i = 0; i < 500; i++) {
    sprintf(contatos[i].nome, "Contato%d", i + 1);
    sprintf(contatos[i].telefone, "123456789%d", i);
    sprintf(contatos[i].email, "contato%d@example.com", i + 1);
  }

  // Abrir o arquivo para escrita
  arquivo = fopen("contatos.txt", "w");

  // Verificar se o arquivo foi aberto com sucesso
  if (arquivo == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return 1;
  }

  // Escrever os contatos no arquivo
  for (int i = 0; i < 500; i++) {
    fprintf(arquivo, "%s\n", contatos[i].nome);
    fprintf(arquivo, "%s\n", contatos[i].telefone);
    fprintf(arquivo, "%s\n", contatos[i].email);
  }

  // Fechar o arquivo
  fclose(arquivo);

  printf("Arquivo contatos.txt criado com sucesso.\n");

  return 0;
}