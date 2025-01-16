#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
#define TAM 6

void preenche_vet(int v[], int tam){
  for (int i = 0; i < tam; i++){
    v[i] = rand()%11;
  }
}

void imprime_vet(int v[], int tam){
  for(int i; i<tam-1;i++){
    printf("\n%d", v[i]);
  }
  printf("\n%d\n",v[tam-1]);
}

void ordena_vet(int v[],int tam){
  int trocou = TRUE;
  int  aux;

  while(trocou == TRUE){
    trocou = FALSE;
    for(int i=0; i< tam-1; i++)
      if(v[i]> v[i+1]){
        aux = v[i];
        
        v[i] = v[i+1];
        v[i+1] = aux;
        trocou = TRUE;
      }
  }
}

int main(){
  int vet[TAM];
  preenche_vet(vet,TAM);
  imprime_vet(vet,TAM);
  ordena_vet(vet,TAM);
  imprime_vet(vet,TAM);
  
}