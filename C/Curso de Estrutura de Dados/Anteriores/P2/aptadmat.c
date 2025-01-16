#include "tadmatriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int linhas_mat(tadmat A) { return A->qlinhas; }

int colunas_mat(tadmat A) { return A->qcolunas; }

char *descrevep(char p1[], char p2[], char p3[]) {
  char *nome_arq = (char *)malloc(30 * sizeof(char));
  char nome_p[15];
  char buffer[15];
  char aux[30] = "\0";

  // AVALIA SINAIS P1
  if (p1[0] == '-') {
    strcpy(buffer, "menos");
  } else if (p1[0] == 'T') {
    strcpy(buffer, "transp");
  } else {
    if (p1[0] == 'A') {
      strcpy(nome_p, "A");
      strcpy(buffer, "NULL");
    } else if (p1[0] == 'B') {
      strcpy(nome_p, "B");
      strcpy(buffer, "NULL");
    } else if (p1[0] == 'C') {
      strcpy(nome_p, "C");
      strcpy(buffer, "NULL");
    } else if (p1[0] == 'D') {
      strcpy(nome_p, "D");
      strcpy(buffer, "NULL");
    } else {
      strcpy(nome_p, p1);
      strcpy(buffer, "NULL");
    }
  }
  if (p1[1] == 'A') {
    strcpy(nome_p, "A");
  } else if (p1[1] == 'B') {
    strcpy(nome_p, "B");
  } else if (p1[1] == 'C') {
    strcpy(nome_p, "C");
  } else if (p1[1] == 'D') {
    strcpy(nome_p, "D");
  } else {
    strcpy(nome_p, p1);
  }

  // ESCREVE EM AUX
  if (strcmp(buffer, "NULL") != 0) {
    if (strlen(aux) > 0) {
      strcat(aux, buffer);
    } else {
      strcpy(aux, buffer);
    }
  }
  if (strlen(nome_p) > 0) {
    if (strlen(aux) > 0) {
      strcat(aux, nome_p);
    } else {
      strcpy(aux, nome_p);
    }
  }

  // AVALIA SINAIS P2
  if (strcmp(p2, "-") == 0) {
    strcpy(buffer, "menos");
  } else if (strcmp(p2, "+") == 0) {
    strcpy(buffer, "mais");
  } else if (strcmp(p2, "x") == 0) {
    strcpy(buffer, "vezes");
  } else {
    strcpy(buffer, "NULL");
  }

  // ESCREVE EM AUX
  if (strcmp(buffer, "NULL") != 0) {
    if (strlen(aux) > 0) {
      strcat(aux, buffer);
    } else {
      strcpy(aux, buffer);
    }
  }

  // AVALIA SINAIS P3
  if (p3[0] == '-') {
    strcpy(buffer, "menos");
  } else if (p3[0] == 'T') {
    strcpy(buffer, "transp");
  } else {
    if (p3[0] == 'A') {
      strcpy(nome_p, "A");
      strcpy(buffer, "NULL");
    } else if (p3[0] == 'B') {
      strcpy(nome_p, "B");
      strcpy(buffer, "NULL");
    } else if (p3[0] == 'C') {
      strcpy(nome_p, "C");
      strcpy(buffer, "NULL");
    } else if (p3[0] == 'D') {
      strcpy(nome_p, "D");
      strcpy(buffer, "NULL");
    } else {
      strcpy(nome_p, p3);
      strcpy(buffer, "NULL");
    }
  }
  if (p3[1] == 'A') {
    strcpy(nome_p, "A");
  } else if (p3[1] == 'B') {
    strcpy(nome_p, "B");
  } else if (p3[1] == 'C') {
    strcpy(nome_p, "C");
  } else if (p3[1] == 'D') {
    strcpy(nome_p, "D");
  } else {
    strcpy(nome_p, p3);
  }

  // ESCREVE EM AUX
  if (strcmp(buffer, "NULL") != 0) {
    if (strlen(aux) > 0) {
      strcat(aux, buffer);
    } else {
      strcpy(aux, buffer);
    }
  }
  if (strlen(nome_p) > 0) {
    if (strlen(aux) > 0) {
      strcat(aux, nome_p);
    } else {
      strcpy(aux, nome_p);
    }
  }

  strcpy(nome_arq, aux);
  strcat(nome_arq, ".txt");
  return nome_arq;
}

void gera_matriz(char *narq, char p1[], char p2[], char p3[]) {
  char *nome_arq = (char *)malloc(30 * sizeof(char));
  char nome_p1[15];
  char nome_p3[15];
  char buffer[15];
  char aux[30] = "\0";

  int x, o, y = 0;

  // AVALIA SINAIS P1
  if (p1[0] == '-') {
    x = -1;
  } else if (p1[0] == 'T') {
    x = 1;
  } else {
    x = 0;
    if (p1[0] == 'A') {
      strcpy(nome_p1, "A.txt");
    } else if (p1[0] == 'B') {
      strcpy(nome_p1, "B.txt");
    } else if (p1[0] == 'C') {
      strcpy(nome_p1, "C.txt");
    } else if (p1[0] == 'D') {
      strcpy(nome_p1, "D.txt");
    } else {
      strcpy(nome_p1, "NULL");
    }
  }

  // AVALIA SINAIS P2
  if (strcmp(p2, "-") == 0) {
    o = -1;
  } else if (strcmp(p2, "+") == 0) {
    o = 0;
  } else if (strcmp(p2, "x") == 0) {
    o = 1;
  } else {
    (o = 100);
  }

  // AVALIA SINAIS P3
  if (p3[0] == '-') {
    y = -1;
  } else if (p3[0] == 'T') {
    y = 1;
  } else {
    y = 0;
    if (p3[0] == 'A') {
      strcpy(nome_p3, "A.txt");
    } else if (p3[0] == 'B') {
      strcpy(nome_p3, "B.txt");
    } else if (p3[0] == 'C') {
      strcpy(nome_p3, "C.txt");
    } else if (p3[0] == 'D') {
      strcpy(nome_p3, "D.txt");
    } else {
      strcpy(nome_p3, "NULL");
    }
  }

  // CARREGANDO MATRIZES
  tadmat m1 = carrega_mat(nome_p1);
  tadmat m2 = carrega_mat(nome_p3);

  if ((x != 0)) {
    if (x == 1) {
      m1 = transp_mat(m1);
    } else if (x == -1) {
      m1 = neg_mat(m1);
    } else {
      x = 0;
    }
  }

  if ((y != 0)) {
    if (y == 1) {
      m2 = transp_mat(m2);
    } else if (x == -1) {
      m2 = neg_mat(m1);
    } else {
      y = 0;
    }
  }

  tadmat m3 = NULL;

  if (o == 0) {
    m1 = soma_mat(m1, m2);
  } else if (o == 1) {
    int l = linhas_mat(m1);
    int c = colunas_mat(m2);
    m3 = cria_mat(l, c);
    m3 = multi_mat(m1, m2);
  } else if (o == -1) {
    m1 = soma_mat(m1, neg_mat(m2));
  } else {
    m1 = NULL;
  }

  if (m3 != NULL)
    salva_mat(m3, narq);
  else
    salva_mat(m1, narq);
}

int main(void) {
  char arquivo[50] = "matops.txt";
  FILE *arq = fopen(arquivo, "rt");

  char p1[3], p2[3], p3[3];
  char *narq;

  while (fscanf(arq, "%s %s %s", p1, p2, p3) == 3) {
    narq = descrevep(p1, p2, p3);
    // CM
    gera_matriz(narq, p1, p2, p3);
    // FM
    free(narq);
  }

  fclose(arq);
  return 0;
}
