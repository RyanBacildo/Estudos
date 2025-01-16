#ifndef TADMATRIZ_H
#define TADMATRIZ_H
#include "tadlista.h"

typedef struct tipo_matriz {
  Lista *linhas;
  int qlinhas;
  int qcolunas;
} *tadmat;

tadmat cria_mat(int qlinhas, int qcolunas);
tadmat soma_mat(tadmat A, tadmat B);
tadmat multi_mat(tadmat A, tadmat B);
tadmat neg_mat(tadmat A);
tadmat transp_mat(tadmat A);
tadmat carrega_mat(char *nome_do_arquivo);
tadmat salva_mat(tadmat A, char *nome_do_arquivo);

#endif