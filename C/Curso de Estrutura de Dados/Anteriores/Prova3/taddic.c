#include "taddic.h"
#include "tadlista.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 17

int fh(t_chave key) {
  int soma = 0;
  int tamstr = strlen(key);

  for (int i = 0; i < tamstr; i++)
    soma = soma + key[i];

  return soma % MAX;
}

t_item find_item(Lista lst, t_chave k) {
  t_item item;
  for (int j = 0; j < lenLista(lst); j++) {
    item = (t_item)dadoLista(lst, j);
    if (strcmp(item->key, k) == 0)
      return item;
  }
  return NULL;
}

Dic criaDic() {
  Dic d = (Lista *)malloc(MAX * sizeof(Lista));
  for (int i = 0; i < MAX; i++)
    d[i] = NULL;
  return d;
}

Dic adDic(Dic d, t_chave k, t_dado dado) {
  int pos_array = fh(k);
  Lista lst;
  t_item item;

  if (d[pos_array] == NULL)
    d[pos_array] = criaLista();

  lst = d[pos_array];

  item = find_item(lst, k);

  if (item == NULL) {
    item = (t_item)malloc(sizeof(struct item_dic));
    item->key = k;
    item->valor = dado;
    appendLista(lst, item);
  } else {
    item->valor = dado;
  }

  return d;
}

int lenDic(Dic d) {
  int total_ks = 0;
  Lista lst;
  for (int i = 0; i < MAX; i++)
    if (d[i] != NULL) {
      lst = d[i];
      total_ks = total_ks + lenLista(lst);
    }
  return total_ks;
}

t_dado dadoDic(Dic d, t_chave k) {
  int pos_array = fh(k);
  Lista lst;
  t_item item;

  if (d[pos_array] == NULL)
    return NULL;

  lst = d[pos_array];

  item = find_item(lst, k);

  if (item == NULL)
    return NULL;
  else
    return item->valor;
}

t_dado removeDic(Dic d, t_chave k) {
  int pos_array = fh(k);
  Lista lst;
  t_item item;
  int i;

  if (d[pos_array] == NULL)
    return NULL;

  lst = d[pos_array];

  for (i = 0; i < lenLista(lst); i++) {
    item = (t_item)dadoLista(lst, i);
    if (strcmp(item->key, k) == 0)
      break;
  }

  if (i == lenLista(lst))
    return NULL;
  else {
    item = removeLista(lst, i);
    return item->valor;
  }
}

Lista keysDic(Dic d) {
  Lista lstks = criaLista();
  Lista lst;
  t_item item;

  for (int i = 0; i < MAX; i++) {
    if (d[i] != NULL) {
      lst = d[i];

      for (int k = 0; k < lenLista(lst); k++) {
        item = (t_item)dadoLista(lst, k);
        appendLista(lstks, item->key);
      }
    }
  }

  return lstks;
}

int inDic(Dic d, t_chave k) {
  Lista lst;
  t_item item;

  for (int i = 0; i < MAX; i++) {
    if (d[i] != NULL) {
      lst = d[i];
      item = find_item(lst, k);
      if (item != NULL)
        return 1;
    }
  }
  return 0;
}

void print_estats(Dic d) {
  for (int i = 0; i < MAX; i++) {
    if (d[i] != NULL)
      printf("%2d,%4d\n", i, lenLista(d[i]));
    else
      printf("%2d, NULL\n", i);
  }
}
