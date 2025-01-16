#include "tadlista.h"
#include <stdio.h>
#include <stdlib.h>

Lista criaLista() {
  Lista l = (Lista)malloc(sizeof(struct tipo_cabec));
  if (l == NULL) {
    puts("Erro: falha na alocação de memória.");
    return NULL;
  }

  l->prim = NULL;
  l->ult = NULL;
  l->cursor = NULL;
  l->pos_cursor = -1;
  l->tam = 0;

  return l;
}

Lista localiza(Lista l, int pos) {
  if ((pos < 0) || (pos > l->tam)) return NULL;

  if (l->tam == 0) {
    l->cursor = NULL;
    l->pos_cursor = -1;
    return l;
  }

  if (pos > l->pos_cursor) {
    for (int i = l->pos_cursor; i < pos; i++) {
      if (l->cursor != NULL) {
        l->cursor = l->cursor->prox;
      } else {
        l->pos_cursor = -1;
        return NULL;
      }
    }
  } else {
    for (int i = pos; i < l->pos_cursor; i++) {
      if (l->cursor != NULL) {
        l->cursor = l->cursor->ant;
      } else {
        l->pos_cursor = -1;
        return NULL;
      }
    }
  }

  l->pos_cursor = pos;
  return l;
}

Lista appendLista(Lista l, t_dado dado) {
  t_noh pnoh = (t_noh)malloc(sizeof(struct tipo_noh));
  if (pnoh == NULL) {
    puts("Erro: falha na alocação de memória.");
    return NULL;
  }

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

  l->pos_cursor = l->tam - 1;
  l->cursor = l->ult;

  return l;
}

int lenLista(Lista l) { return l->tam; }

t_dado dadoLista(Lista l, int pos) {
  if (localiza(l, pos) == NULL)
    return NULL;
  else
    return l->cursor->dado;
}

Lista insereLista(Lista l, t_dado dado, int pos) {
  if (pos == l->tam) {
    appendLista(l, dado);
    return l;
  }

  t_noh noh = (t_noh)malloc(sizeof(struct tipo_noh));
  if (noh == NULL) {
    puts("Erro: falha na alocação de memória.");
    return NULL;
  }

  if (localiza(l, pos) == NULL)
    return l;
  else {
    noh->dado = dado;
    noh->prox = NULL;
    noh->ant = NULL;

    if (pos == 0) {
      noh->prox = l->prim;
      l->prim->ant = noh;
      l->prim = noh;
    } else {
      noh->prox = l->cursor;
      noh->ant = l->cursor->ant;
      l->cursor->ant->prox = noh;
      l->cursor->ant = noh;
    }
  }

  l->cursor = noh;
  l->tam++;

  return l;
}

t_dado removeLista(Lista l, int pos) {
  if (localiza(l, pos) == NULL || l->tam == 0) {
    return NULL;
  } else {
    t_noh removido = l->cursor;
    t_dado valor = removido->dado;

    if (pos == 0) {
      l->prim = l->prim->prox;
      l->cursor = l->prim;
    } else if (pos == l->tam - 1) {
      l->ult = l->ult->ant;
      l->cursor = l->ult;
    } else {
      t_noh aux = removido->ant;
      removido->ant->prox = removido->prox;
      removido->prox->ant = removido->ant;
      l->cursor = removido->prox;
    }

    free(removido);
    l->tam--;

    return valor;
  }
}

Lista destroiLista(Lista l) {
  while (l->tam > 0) {
    removeLista(l, 0);
  }
  free(l);
  return NULL;
}