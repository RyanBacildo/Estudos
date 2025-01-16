#include <stdio.h>
#include <stdlib.h>

void cria_mat(int l, int c, int m[l][c]) {
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      m[i][j] = rand() % 90 + 10;
    }
  }
}

void print_mat(int l, int c, int m[l][c]) {
  for (int i = 0; i < l; i++) {
    for (int j = 0; j < c; j++) {
      printf(" %d", m[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int ln,cl;
  printf("Número de linhas: ");
  scanf("%d",&ln);
  printf("Número de colunas: ");
  scanf("%d",&cl);
  int mt[ln][cl];
  cria_mat(ln, cl, mt);
  print_mat(ln,cl,mt);
  return 0;
}

/*
void troca_linhas(int mat[][4],int colunas,int trocai, int trocaj){
  int aux;
  for(int k=0; k < colunas; k++){
      aux = mat[trocai][k];
      mat[trocai][k] = mat[trocaj][k];
      mat[trocaj][k] = aux;
  }
}
int main() {

  int m[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
  for (i=0;i<5;i++){
     preenche_vet(m[i], TAM);
  }
  int i,j,aux;

  troca_linhas(m,4,2,3);

  return 0;
}

int main(){


  for(int i=0;i<ln;i++){
    for(int j=0;j<cl;j++){
      printf(" %d",mt[i][j]);
    }
    printf("\n");
  }
  return 0

  return 0;
}
*/