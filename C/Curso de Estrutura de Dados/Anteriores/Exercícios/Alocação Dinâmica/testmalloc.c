#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char nome[50];
  int numero;
  char email[50];
} tcontato;

void for_struct(tcontato *contatos, char a[], char b[], char c[])
{
  tcontato contato;
  int i = 0;

  a[strcspn(a, "\n")] = '\0';
  b[strcspn(b, "\n")] = '\0';
  c[strcspn(c, "\n")] = '\0';

  
  strcpy(a, contato.nome);
  contato.numero = atoi(b);
  strcpy(c, contato.email);
  
}

int main(void){

  FILE *arq;
  arq = fopen("./contatos.txt", "rt");

  if (arq == NULL){
    puts("Arquivo não encontrado!");
    return -1;
  }
  
  char nome[50], numero [50], email[50];
  tcontato contatos[500];

  fgets(nome, 50, arq);
  fgets(numero, 50, arq);
  fgets(email, 50, arq);

  for_struct(contatos,nome,numero,email);
  
  return 0;
}