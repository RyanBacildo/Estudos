#include "tadlista.h"
#include <stdio.h>
#include <stdlib.h>

Lista criaLista() {
  Lista l = (Lista)malloc(sizeof(t_cabec));
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
  if (pos < 0 || pos >= l->tam) return NULL;

  if (pos > l->tam / 2) {
    l->cursor = l->ult;
    for (int i = l->tam - 1; i > pos; i--) {
      l->cursor = l->cursor->ant;
    }
  } else {
    l->cursor = l->prim;
    for (int i = 0; i < pos; i++) {
      l->cursor = l->cursor->prox;
    }
  }

  l->pos_cursor = pos;
  return l;
}

Lista appendLista(Lista l, t_dado dado) {
  t_noh pnoh = (t_noh)malloc(sizeof(struct tipo_noh));
  if (pnoh == NULL) {
    puts("Erro: falha na alocação de memória.");
    return l;
  }

  pnoh->dado = dado;
  pnoh->prox = NULL;
  pnoh->ant = l->ult;

  if (l->tam == 0) {
    l->prim = pnoh;
  } else {
    l->ult->prox = pnoh;
  }

  l->ult = pnoh;
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
    return appendLista(l, dado);
  }

  if (pos == 0) {
    t_noh noh = (t_noh)malloc(sizeof(struct tipo_noh));
    if (noh == NULL) {
      puts("Erro: falha na alocação de memória.");
      return l;
    }

    noh->dado = dado;
    noh->prox = l->prim;
    noh->ant = NULL;

    if (l->prim != NULL) {
      l->prim->ant = noh;
    }

    l->prim = noh;
    l->tam++;

    l->pos_cursor = 0;
    l->cursor = l->prim;

    return l;
  }

  if (localiza(l, pos) == NULL)
    return l;

  t_noh noh = (t_noh)malloc(sizeof(struct tipo_noh));
  if (noh == NULL) {
    puts("Erro: falha na alocação de memória.");
    return l;
  }

  noh->dado = dado;
  noh->prox = l->cursor;
  noh->ant = l->cursor->ant;

  if (l->cursor->ant != NULL) {
    l->cursor->ant->prox = noh;
  }

  l->cursor->ant = noh;

  l->cursor = noh;
  l->tam++;

  return l;
}

t_dado removeLista(Lista l, int pos) {
  if (localiza(l, pos) == NULL || l->tam == 0) {
    return NULL;
  }

  t_noh removido = l->cursor;
  t_dado valor = removido->dado;

  if (pos == 0) {
    l->prim = l->prim->prox;
    if (l->prim != NULL) {
      l->prim->ant = NULL;
    }
    l->cursor = l->prim;
  } else if (pos == l->tam - 1) {
    l->ult = l->ult->ant;
    if (l->ult != NULL) {
      l->ult->prox = NULL;
    }
    l->cursor = l->ult;
  } else {
    t_noh aux_ant = removido->ant;
    t_noh aux_prox = removido->prox;
    aux_ant->prox = aux_prox;
    aux_prox->ant = aux_ant;
    l->cursor = aux_prox;
  }

  free(removido);
  l->tam--;

  if (pos == l->tam) {
    l->pos_cursor = pos - 1;
  }

  return valor;
}

Lista destroiLista(Lista l) {
  while (l->tam > 0) {
    removeLista(l, 0);
  }
  free(l);
  return NULL;
}