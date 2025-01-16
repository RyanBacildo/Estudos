#include <stdio.h>
#include <string.h>

typedef struct tipo_coords {
                 int lat;
                 int longi;
                 struct tipo_coords *ant;
                 struct tipo_coords *prox;
                } t_coords;

int main(){
  t_coords c = {23, 67, NULL, NULL};

  c.prox = (struct tipo_coords *) malloc(sizeof(t_coords));
  c.prox->lat = 100;
  c.prox->longi = 200;
  c.prox->ant = &c;
  c.prox->prox = NULL;


  return 0;
}