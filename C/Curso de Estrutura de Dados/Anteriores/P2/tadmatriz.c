#include "tadmatriz.h"
#include "tadlista.h"
#include <stdio.h>
#include <stdlib.h>

tadmat cria_mat(int qlinhas, int qcolunas) {
tadmat matriz = (tadmat)malloc(sizeof(struct tipo_matriz));
if (matriz == NULL) {
  puts("Erro: falha na alocação de memória.");
  return NULL;
}

  matriz->qlinhas = qlinhas;
  matriz->qcolunas = qcolunas;

  matriz->linhas = (Lista *)malloc(qlinhas * sizeof(Lista));
  if (matriz->linhas == NULL) {
    free(matriz);
    puts("Erro: falha na alocação de memória.");
    return NULL;
  }

  for (int i = 0; i < qlinhas; i++) {
    matriz->linhas[i] = criaLista();
    for (int j = 0; j < qcolunas; j++) {
      int *valor = (int *)malloc(sizeof(int));
      *valor = 0;
      appendLista(matriz->linhas[i], (t_dado)valor);
    }
  }

  return matriz;
}

tadmat soma_mat(tadmat A, tadmat B) {
  if (A->qlinhas != B->qlinhas || A->qcolunas != B->qcolunas) {
    puts("Erro: as matrizes têm dimensões diferentes e não podem ser somadas.");
    return NULL;
  }

  tadmat resultado = cria_mat(A->qlinhas, A->qcolunas);

  for (int i = 0; i < A->qlinhas; i++) {
    for (int j = 0; j < A->qcolunas; j++) {
      int *soma = (int *)malloc(sizeof(int));
      *soma = *((int *)dadoLista(A->linhas[i], j)) +
              *((int *)dadoLista(B->linhas[i], j));
      insereLista(resultado->linhas[i], (t_dado)soma, j);
    }
  }

  return resultado;
}

tadmat multi_mat(tadmat A, tadmat B) {
  if (A->qcolunas != B->qlinhas) {
    puts("Erro: o número de colunas da matriz A não é igual ao número de linhas da matriz B e, portanto, não podem ser multiplicadas.");
    return NULL;
  }

  tadmat resultado = cria_mat(A->qlinhas, B->qcolunas);

  for (int i = 0; i < A->qlinhas; i++) {
    for (int j = 0; j < B->qcolunas; j++) {
      int *valor = (int *)malloc(sizeof(int));
      *valor = 0;
      for (int k = 0; k < A->qcolunas; k++) {
        *valor += *((int *)dadoLista(A->linhas[i], k)) *
                  *((int *)dadoLista(B->linhas[k], j));
      }
      insereLista(resultado->linhas[i], (t_dado)valor, j);
    }
  }

  return resultado;
}

tadmat neg_mat(tadmat A) {
  tadmat resultado = cria_mat(A->qlinhas, A->qcolunas);

  for (int i = 0; i < A->qlinhas; i++) {
    for (int j = 0; j < A->qcolunas; j++) {
      int *valor = (int *)malloc(sizeof(int));
      *valor = -(*((int *)dadoLista(A->linhas[i], j)));
      insereLista(resultado->linhas[i], (t_dado)valor, j);
    }
  }

  return resultado;
}

tadmat transp_mat(tadmat A) {
  tadmat resultado = cria_mat(A->qcolunas, A->qlinhas);

  for (int i = 0; i < A->qlinhas; i++) {
    for (int j = 0; j < A->qcolunas; j++) {
      int *valor = (int *)malloc(sizeof(int));
      *valor = *((int *)dadoLista(A->linhas[i], j));
      insereLista(resultado->linhas[j], (t_dado)valor, i);
    }
  }

  return resultado;
}

tadmat carrega_mat(char *nome_do_arquivo) {
  FILE *file = fopen(nome_do_arquivo, "rt");
  if (file == NULL) {
    printf("Erro: não foi possível abrir o arquivo %s.\n", nome_do_arquivo);
    return NULL;
  }

  int qlinhas, qcolunas;
  fscanf(file, "%d %d", &qlinhas, &qcolunas);

  tadmat matriz = cria_mat(qlinhas, qcolunas);

  for (int i = 0; i < qlinhas; i++) {
    for (int j = 0; j < qcolunas; j++) {
      int valor;
      fscanf(file, "%d", &valor);
      insereLista(matriz->linhas[i], (t_dado)malloc(sizeof(int)), j);
      *((int *)dadoLista(matriz->linhas[i], j)) = valor;
    }
  }

  fclose(file);

  return matriz;
}

tadmat salva_mat(tadmat A, char *nome_do_arquivo) {
  FILE *file = fopen(nome_do_arquivo, "wt");
  if (file == NULL) {
    printf("Erro: não foi possível abrir o arquivo %s.\n", nome_do_arquivo);
    exit(1);
  }

  fprintf(file, "%d %d\n", A->qlinhas, A->qcolunas);

  for (int i = 0; i < A->qlinhas; i++) {
    for (int j = 0; j < A->qcolunas; j++) {
      fprintf(file, "%d ", *((int *)dadoLista(A->linhas[i], j)));
    }
    fprintf(file, "\n");
  }

  fclose(file);

  return A;
}