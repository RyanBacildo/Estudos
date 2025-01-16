#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct tipo_coords {
                 int lat;
                 int longi;
                 struct tipo_coords *ant;
                 struct tipo_coords *prox;
                } t_coords;

int main(){
  t_coords *inicio;
  t_coords *final;

  inicio = (t_coords *)malloc(sizeof(struct tipo_coords));
  final = inicio;

  for(int i=0; i < 2; i++){
    final->prox = (t_coords *)malloc(sizeof(struct tipo_coords));
    final->prox->ant = final;
    final = final->prox;     
  }

  final->prox = NULL;

  puts("Concluido!!!");

  return 0;
}