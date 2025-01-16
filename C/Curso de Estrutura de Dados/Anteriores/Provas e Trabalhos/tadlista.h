typedef void *t_dado;

typedef struct tipo_noh {
  t_dado dado;
  struct tipo_noh *ant;
  struct tipo_noh *prox;
} *t_noh;

typedef struct tipo_cabec {
  int tam;

  int cursor_ndx;
  t_noh cursor_ptr;

  t_noh prim;
  t_noh ult;
} t_cabec;

typedef t_cabec *Lista;

Lista criaLista();
Lista appendLista(Lista l,t_dado dado);
int lenLista(Lista l);
t_dado dadoLista(Lista l,int pos);
Lista insereLista(Lista l,t_dado dado,int pos);
t_dado removeLista(Lista l, int pos);
Lista destroiLista(Lista l);