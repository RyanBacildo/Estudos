#ifndef ___T__AD_D__I_C__

#define ___T__AD_D__I_C__

#include "tadlista.h"

typedef void *t_dado;

typedef struct item_dic {
  char *key;
  t_dado valor;
} *t_item;

typedef char *t_chave;

typedef Lista *Dic;

// PUBLICO, VC PODE INVOCAR ESTAS FUNÇÕES NA APLICAÇÃO
Dic criaDic();
Dic adDic(Dic d, t_chave k, t_dado valor);
int lenDic(Dic d);
t_dado dadoDic(Dic d, t_chave k);
t_dado removeDic(Dic d, t_chave k);
Lista keysDic(Dic d);
int inDic(Dic d,  t_chave k);
void print_estats(Dic d); 


#endif