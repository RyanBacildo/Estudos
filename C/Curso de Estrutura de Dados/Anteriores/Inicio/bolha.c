#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int vetor[], int n) {
  int i, j, aux;

  for (i = 1; i < n; i++) {
    printf("\n[%d] ", i);

    for (j = 0; j < n - 1; j++) {
      printf("%d, ", j);

      if (vetor[j] > vetor[j + 1]) {
        aux = vetor[j];
        vetor[j] = vetor[j + 1];
        vetor[j + 1] = aux;
      }
    }
  }
}

int main(void) {
  int i;
  
  for (i = 0; i < 10; i++) {  
    printf("%d ", rand() % 5);
  }
  return 0;
}