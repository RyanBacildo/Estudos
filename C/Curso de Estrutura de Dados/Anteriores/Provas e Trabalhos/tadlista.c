#include "tadlista.h"
#include <stdio.h>
#include <stdlib.h>

Lista criaLista() {
  Lista l = (Lista)malloc(sizeof(t_cabec));
  l->prim = NULL;
  l->ult = NULL;
  l->cursor_ptr = NULL;
  l->cursor_ndx = -1;
  l->tam = 0;

  return l;
}

Lista localiza(Lista l, int pos) {
  if ((pos < 0) || (pos >= l->tam))
    return NULL;

  if (pos > l->cursor_ndx) {
    for (int i = l->cursor_ndx; i < pos; i++) {
      l->cursor_ptr = l->cursor_ptr->prox;
    }
  } else {
    for (int i = pos; i < l->cursor_ndx; i++) {
      l->cursor_ptr = l->cursor_ptr->ant;
    }
  }

  l->cursor_ndx = pos;

  return l;
}

Lista appendLista(Lista l, t_dado dado) {
  t_noh pnoh = (t_noh)malloc(sizeof(struct tipo_noh));
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

  l->cursor_ndx = l->tam - 1;
  l->cursor_ptr = l->ult;

  return l;
}

int lenLista(Lista l) { return l->tam; }

t_dado dadoLista(Lista l, int pos) {
  if (localiza(l, pos) == NULL)
    return NULL;
  else
    return l->cursor_ptr->dado;
}

Lista insereLista(Lista l, t_dado dado, int pos) {
  if(pos == l->tam){
    appendLista(l,dado);
    return l;
  }

  t_noh noh = (t_noh)malloc(sizeof(struct tipo_noh));

  if (localiza(l, pos) == NULL)
    return l;
  else {
    noh->dado = dado;
    noh->prox = NULL;
    noh->ant = NULL;
-
    if(pos == 0){ // primeira posição de uma lista não vazia.
        noh->prox = l->prim;
        l->prim->ant = noh;
        l->prim = noh;
    }
    else { // qualquer posição entre a 1 e a última (inclusive) de uma 
           // lista não vazia.        
        noh->prox = l->cursor_ptr;
        noh->ant = l->cursor_ptr->ant;
        l->cursor_ptr->ant->prox = noh;
        l->cursor_ptr->ant = noh;
    }
  }

  l->cursor_ptr = noh;        
  l->tam++;

  return l;
}

t_dado removeLista(Lista l, int pos) {
  if (localiza(l, pos) == NULL)
    return NULL;
  else {
    // faz a remoção
  }

  return NULL;
}

Lista destroiLista(Lista l){
  int i;
  for(i=0; i < lenLista(l); i++)
    removeLista(l,0);
  free(l);
  return NULL;
}