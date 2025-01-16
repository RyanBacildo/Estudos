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

typedef t_cabec *Lista;

Lista criaLista(){
  Lista l = (Lista)malloc(sizeof(t_cabec));
  l->prim = NULL;
  l->ult = NULL;
  l->tam = 0;
  return l;
}

Lista append(Lista l,int dado){ 
  t_noh *pnoh = (t_noh *)malloc(sizeof(t_noh));
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

int len(Lista l){
  return l->tam;
}

int main(){
  Lista lst = criaLista();
  int i;

  append(lst,45);  
  append(lst,200); 
  append(lst,1025); 

  return 0;
}