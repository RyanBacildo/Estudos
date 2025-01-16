#include "tadlista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  puts("INSERINDO 10 ELEMENTOS SOMENTE NA POSIÇÂO ZERO");
  printf("Lista (insereLista(lst,p,0))\n");

  Lista lst = criaLista();

  for (int i = 0; i < 10; i++) {
    int *p = (int *)malloc(sizeof(int));
    *p = i + 1;
    insereLista(lst, p, 0);
  }

  for (int i = 0; i < 10; i++) {
    int *p = (int *)dadoLista(lst, i);
    printf("%d,", *p);
  }

  printf("\n");

  // destroiLista(lst);-----------------------
  puts("\nREMOVENDO 10 ELEMENTOS SOMENTE USANDO A POSIÇÂO ZERO");
  printf("tamanho da lista ANTES removeLista: %d\n", lenLista(lst));

  // -Não checa se lst é inicialmente NULL.
  // -Não invoca removeLista.
  // -Dado continua povoando o stack.
  // Abaixo, o que removeLista deveria fazer.
  for (int i = 0; i < 10; i++) {
    int *p = (int *)removeLista(lst, 0);
    free(p);
  }

  printf("tamanho da lista DEPOIS removeLista: %d\n", lenLista(lst));

  free(lst);
  //-----------------------------------------

  puts("\nINSERINDO 10 ELEMENTOS VIA APPEND");
  printf("Nova lista (appendLista(lst,p))\n");

  lst = criaLista();

  for (int i = 0; i < 10; i++) {
    int *p = (int *)malloc(sizeof(int));
    *p = i + 1;
    appendLista(lst, p);
  }

  for (int i = 0; i < 10; i++) {
    int *p = (int *)dadoLista(lst, i);
    printf("%d,", *p);
  }

  printf("\n");

  // destroiLista(lst);-----------------------
  puts("\nREMOVENDO 10 ELEMENTOS SOMENTE USANDO A POSIÇÂO ZERO");
  printf("tamanho da lista ANTES removeLista(lst,0): %d\n", lenLista(lst));

  // -Não checa se lst é inicialmente NULL.
  // -Não invoca removeLista.
  // -Dado continua povoando o stack.
  // Abaixo, o que removeLista deveria fazer.
  for (int i = 0; i < 10; i++) {
    int *p = (int *)removeLista(lst, 0);
    free(p);
  }

  printf("tamanho da lista DEPOIS removeLista(lst,0): %d\n", lenLista(lst));

  free(lst);
  //-----------------------------------------

  puts("\nINSERINDO 10 ELEMENTOS VIA APPEND");
  printf("Nova Nova lista (appendLista(lst,p))\n");

  lst = criaLista();

  for (int i = 0; i < 10; i++) {
    int *p = (int *)malloc(sizeof(int));
    *p = i + 1;
    appendLista(lst, p);
  }

  for (int i = 0; i < 10; i++) {
    int *p = (int *)dadoLista(lst, i);
    printf("%d,", *p);
  }

  printf("\n");

  // destroiLista(lst);-----------------------
  puts("\nREMOVENDO 10 ELEMENTOS SOMENTE USANDO A ÚLTIMA POSIÇÃO DA LISTA");
  printf("tamanho da lista ANTES removeLista(lst,lenLista(lst)-1): %d\n",
         lenLista(lst));

  // -Não checa se lst é inicialmente NULL.
  // -Não invoca removeLista.
  // -Dado continua povoando o stack.
  // Abaixo, o que removeLista deveria fazer.
  for (int i = lenLista(lst) - 1; i >= 0; i--) {
    removeLista(lst, i);
  }

  printf("tamanho da lista DEPOIS removeLista(lst,lenLista(lst)-1): %d\n",
         lenLista(lst));

  free(lst);
  //-----------------------------------------

  puts("\nINSERINDO 10 ELEMENTOS NA ÚLTIMA POSIÇÃO DA LISTA");
  printf("Nova Nova Nova lista (insereLista(lst,p,lenLista(lst))\n");

  lst = criaLista();

  for (int i = 0; i < 10; i++) {
    int *p = (int *)malloc(sizeof(int));
    *p = i + 1;
    insereLista(lst, p, lenLista(lst));
  }

  for (int i = 0; i < 10; i++) {
    int *p = (int *)dadoLista(lst, i);
    printf("%d,", *p);
  }

  printf("\n");

  // destroiLista(lst);-----------------------
  puts("\nREMOVENDO 10 ELEMENTOS SOMENTE USANDO A ÚLTIMA POSIÇÃO DA LISTA");
  printf("tamanho da lista ANTES removeLista(lst,lenLista(lst)-1): %d\n",
         lenLista(lst));

  // -Não checa se lst é inicialmente NULL.
  // -Não invoca removeLista.
  // -Dado continua povoando o stack.
  // Abaixo, o que removeLista deveria fazer.
  
  for (int i = 0; i < 10; i++) {
    removeLista(lst, lenLista(lst) - 1);
  }
  

  printf("tamanho da lista DEPOIS removeLista(lst,lenLista(lst)-1): %d\n",lenLista(lst));

  free(lst);
  //-----------------------------------------

  int arraypos[5] = {1, 3, 5, 7, 9};

  puts("\nINSERINDO 5 ELEMENTOS ENTRE A PRIMEIRA E A ÚLTIMA POSIÇÃO DA LISTA");
  printf("Nova Nova Nova lista (insereLista(lst,p,pos)\n");

  lst = criaLista();

  for (int i = 0; i < 10; i++) {
    int *p = (int *)malloc(sizeof(int));
    *p = i + 1;
    insereLista(lst, p, lenLista(lst));
  }

  for (int i = 0; i < 5; i++) {
    int *p = (int *)malloc(sizeof(int));
    *p = (i + 1) * 100;
    insereLista(lst, p, arraypos[i]);
  }

  for (int i = 0; i < lenLista(lst); i++) {
    int *p = (int *)dadoLista(lst, i);
    printf("%d,", *p);
  }

  printf("\n");

  // destroiLista(lst);-----------------------
  puts("\nREMOVENDO 5 ELEMENTOS ENTRE A PRIMEIRA E A ÚLTIMA POSIÇÃO DA LISTA");
  printf("tamanho da lista ANTES removeLista(lst,pos): %d\n", lenLista(lst));

  // -Não checa se lst é inicialmente NULL.
  // -Não invoca removeLista.
  // -Dado continua povoando o stack.
  // Abaixo, o que removeLista deveria fazer.
  for (int i = 0; i < 5; i++) {
    int *p = (int *)removeLista(lst, arraypos[i]);
    free(p);
  }

  printf("tamanho da lista DEPOIS removeLista(lst,pos): %d\n", lenLista(lst));

  for (int i = 0; i < lenLista(lst); i++) {
    int *p = (int *)dadoLista(lst, i);
    printf("%d,", *p);
  }

  free(lst);

  printf("\n CONCLUÍDO!!!");

  return 0;
}