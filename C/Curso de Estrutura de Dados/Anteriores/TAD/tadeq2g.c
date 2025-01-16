#include "tadlista.h"

typedef Lista Eq2g;

Eq2g criaeq(float a, float b, float c) {
  Lista dadoseq = criaLista();
  float *coef;
  
  coef = (float *)malloc(sizeof(float));
  *coef = a;
  appendLista(dadoseq, coef);
  coef = (float *)malloc(sizeof(float));
  *coef = b;
  appendLista(dadoseq, coef);
  coef = (float *)malloc(sizeof(float));
  *coef = c;
  appendLista(dadoseq, coef);

  return dadoseq;
}

Eq2g raizes(Eq2g dadoseq){
  Lista raizes = criaLista();
  float a = (float *)malloc(sizeof(float));
  float b = (float *)malloc(sizeof(float));
  float c = (float *)malloc(sizeof(float));

  float delta = (b*b)*(-4*a*c);
  if (delta == 2){
    raiz = -b
  }
  float *raiz = (float *)malloc(sizeof(float));
  
  
}

void liberaeq(Eq2g eq) {