#include "taddic.h"
#include <stdio.h>
#include <stdlib.h>

void destroi_dic(Dic d);

int main() {
    Dic meuDic = criaDic(); // Cria um novo dicionário

    // Adiciona elementos ao dicionário
    adDic(meuDic, "chave1", "valor1");
    adDic(meuDic, "chave2", "valor2");
    adDic(meuDic, "chave3", "valor3");

    // Imprime o valor associado a uma chave
    t_dado valorChave2 = dadoDic(meuDic, "chave2");
    if (valorChave2 != NULL) {
        printf("Valor associado à chave 'chave2': %s\n", (char *)valorChave2);
    } else {
        printf("Chave 'chave2' não encontrada\n");
    }

    // Remove um elemento do dicionário
    t_dado valorRemovido = removeDic(meuDic, "chave1");
    if (valorRemovido != NULL) {
        printf("Valor removido: %s\n", (char *)valorRemovido);
    } else {
        printf("Chave 'chave1' não encontrada\n");
    }

    // Imprime o tamanho do dicionário
    printf("Tamanho do dicionário: %d\n", lenDic(meuDic));

    // Imprime todas as chaves do dicionário
    Lista chaves = keysDic(meuDic);
    printf("Chaves do dicionário: ");
    for (int i = 0; i < lenLista(chaves); i++) {
        printf("%s ", (char *)dadoLista(chaves, i));
    }
    printf("\n");

    // Libera a memória alocada para o dicionário e chaves
  
    destroiLista(chaves);

    return 0;
}

void destroi_dic(Dic d) {
  for (int i = 0; i < 17; i++) {
    if (d[i] != NULL) {
      Lista lst = d[i];
      t_item item;

      for (int j = 0; j < lenLista(lst); j++) {
        item = (t_item)dadoLista(lst, j);
        free(item->key); // Libera a chave
        free(item);      // Libera o item
      }

      destroiLista(lst); // Libera a lista
    }
  }

  free(d); // Libera o array de listas
}