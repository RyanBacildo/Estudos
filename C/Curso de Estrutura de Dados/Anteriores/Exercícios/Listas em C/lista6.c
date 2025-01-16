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
  Lista lstints = criaLista();
  Lista lstfloats = criaLista();
  Lista lststrings = criaLista();
  int i;
  int *p;
  float *f;
  char *s;

  p = (int *)malloc(sizeof(int));
  *p = 45;
  appendLista(lstints,p);

   f = (float *)malloc(sizeof(float));
  *f = 20.456;    
  appendLista(lstfloats,f); 

  s = (char *)malloc(32 * sizeof(char));
  strcpy(s,"Daniele");    
  appendLista(lststrings,s); 

  s = (char *)malloc(32 * sizeof(char));
  strcpy(s,"Irene");    
  appendLista(lststrings,s);

  s = (char *)malloc(32 * sizeof(char));
  strcpy(s,"Larissa");    
  appendLista(lststrings,s);

  printf("Esta lista possui %d nós.\n",lenLista(lststrings));

  for(int k=0; k < lenLista(lststrings); k++)
    printf("%s\n",(char *)dadoLista(lststrings,k));

  return 0;
}