#include <stdio.h>
#include <string.h>

typedef struct tipo_coords {
  int lat;
  int longi;
  struct tipo_coords *ant;
  struct tipo_coords *prox;
} t_coords;

int main() {
  t_coords c = {23, 56, NULL, NULL};
  t_coords d = {100, 35, NULL, NULL};
  t_coords e = {67, 89, NULL, NULL};

  c.ant = NULL;
  c.prox = &d;

  d.ant = &c;
  d.prox = &e;

  e.ant = &d;
  e.prox = NULL;

  return 0;
}