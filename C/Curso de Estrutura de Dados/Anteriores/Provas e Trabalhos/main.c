#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef void *t_dado;

typedef struct tipo_noh {
  t_dado dado;
  struct tipo_noh *ant;
  struct tipo_noh *prox;
} *t_noh;

typedef struct tipo_cabec {
  int tam;
  t_noh prim;
  t_noh ult;
} t_cabec;

typedef t_cabec *Lista;

Lista criaLista(){
  Lista l = (Lista)malloc(sizeof(t_cabec));
  l->prim = NULL;
  l->ult = NULL;
  l->tam = 0;
  return l;
}

Lista appendLista(Lista l,t_dado dado){ 
  t_noh pnoh = (t_noh)malloc(sizeof(struct tipo_noh));
  pnoh->dado = dado;
  pnoh->prox = NULL;
  pnoh->ant = NULL;

  if(l->tam == 0){
    l->prim = pnoh;
    l->ult = pnoh;
  }
  else {
    l->ult->prox = pnoh;
    pnoh->ant = l->ult;
    l->ult = pnoh;      
  }
  l->tam++;

  return l;
}

int lenLista(Lista l){
  return l->tam;
}

t_dado dadoLista(Lista l,int pos){
  if((pos < 0) || (pos >= l->tam))
    return NULL;

  t_noh cursor = l->prim;
  for(int i=0; i < pos; i++)
    cursor = cursor->prox;

  return cursor->dado;  
}

int main(){
  Lista l = criaLista();
  l = appendLista(l,"teste");
  l = appendLista(l,"teste2");
  l = appendLista(l,"teste3");
  l = appendLista(l,"teste4");
  printf("%p", dadoLista(l,2));
  return 0;
}