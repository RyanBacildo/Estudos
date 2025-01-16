#include <stdio.h>
#include <stdlib.h>

typedef struct tipo_noh {
  int dado;
  struct tipo_noh *ant;
  struct tipo_noh *prox;
} t_noh;

typedef struct tipo_cabec {
  int tam;
  t_noh *prim;
  t_noh *ult;
} t_cabec;

typedef t_cabec Lista;

void criaLista(Lista *l) {
  l->prim = NULL;
  l->ult = NULL;
  l->tam = 0;
}

void append(Lista *l, int dado) {
  t_noh *pnoh = (t_noh *)malloc(sizeof(t_noh));
  pnoh->dado = dado;
  pnoh->prox = NULL;
  pnoh->ant = NULL;

  if (l->tam == 0) {
    l->prim = pnoh;
    l->ult = pnoh;
  } else {
    l->ult->prox = pnoh;
    pnoh->ant = l->ult;
    l->ult = pnoh;
  }
  l->tam++;
}

int main() {
  Lista lst;
  int i;

  criaLista(&lst);

  append(&lst, 45);
  append(&lst, 200);
  append(&lst, 1025);

  t_noh *aux = lst.prim;

  i = 0;
  while (i < lst.tam) {
    printf("%d\n", aux->dado);
    aux = aux->prox;
    i++;
  }

  return 0;
}