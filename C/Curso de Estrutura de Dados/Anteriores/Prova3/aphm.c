#include "taddic.h"
#include "tadlista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void destroiDic(Dic d) {
  for (int i = 0; i < 17; i++) {
    if (d[i] != NULL) {
      Lista lst = d[i];
      t_item item;

      while (lenLista(lst) > 0) {
        item = (t_item)removeLista(lst, 0);
        free(item->key); // Libera a chave
        free(item);      // Libera o item
      }

      destroiLista(lst); // Libera a lista
    }
  }

  free(d); // Libera o array de listas
}

Dic carregaDic(char *nomearq) {
  FILE *arquivo = fopen(nomearq, "r");
  if (arquivo == NULL) {
    perror("Erro ao abrir o arquivo");
    exit(EXIT_FAILURE);
  }

  Dic dicionario = criaDic();
  char linha[128];

  while (fgets(linha, sizeof(linha), arquivo) != NULL) {
    char *chave = strtok(linha, ",");
    char *valor = strtok(NULL, "\n");

    if (chave != NULL && valor != NULL) {
      dicionario = adDic(dicionario, strdup(chave), strdup(valor));
    }
  }

  fclose(arquivo);
  return dicionario;
}

int main() {
  Dic pt_en = carregaDic("exemplo.txt");
  Dic pt_es = carregaDic("di-pt-es.txt");
  Dic pt_fr = carregaDic("di-pt-fr.txt");

  printf("ED TRANSLATOR VERSÃO 1.0\n");

  char origem[3], destino[3], palavra[64];

  while (1) {
    printf("TRADUZIR DO IDIOMA (pt,en,fr,es): ");
    scanf("%s", origem);

    if (strcmp(origem, "FIM") == 0) {
      break;
    }

    printf("PARA O IDIOMA (pt,en,fr,es): ");
    scanf("%s", destino);

    printf("ENTRE COM A PALAVRA A TRADUZIR: ");
    scanf("%s", palavra);

    char chaveMaster[6];
    sprintf(chaveMaster, "%s-%s", origem, destino);

    Dic dicSelecionado = dadoDic(pt_en, chaveMaster);

    if (dicSelecionado != NULL) {
      t_dado traducao = dadoDic(dicSelecionado, palavra);

      if (traducao != NULL) {
        printf("TRADUÇÃO: %s\n", (char *)traducao);
      } else {
        printf("PALAVRA NÃO ENCONTRADA!\n");
      }
    } else {
      printf("Dicionário não encontrado!\n");
    }

    printf("----------------------------------------------\n");
  }

  destroiDic(pt_en);
  destroiDic(pt_es);
  destroiDic(pt_fr);

  return 0;
}
