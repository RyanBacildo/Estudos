#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
char placa[8];
char marca[16];
char modelo[32];
char cpf[16];
} t_item_v;

typedef struct{
char cpf[16];
char nome[32];
char email[32];
char celular[16];
}t_item_p;

typedef struct{
char placa[8];
char data[16];
float valor;
}t_item_m;

typedef struct{
int tam;
t_item_v v_veiculos[100];
}t_tab_v;

typedef struct{
int tam;
t_item_p v_proprietarios[100];
}t_tab_p;

typedef struct{
int tam;
t_item_m v_multas[100];
}t_tab_m;

t_tab_v loadTabV(char filename[]){
  t_tab_v tab_veiculos;
  tab_veiculos.tam=0;

  t_item_v v;

  FILE* arq = fopen(filename, "rt");

  if(fscanf(arq, "%[^,],%[^,],%[^,],%[^,\n]\n", 
    v.placa, v.marca, v.modelo, v.cpf) == 4){

    while(fscanf(arq, "%[^,],%[^,],%[^,],%[^,\n]\n", 
      v.placa, v.marca, v.modelo, v.cpf) == 4){

      tab_veiculos.v_veiculos[tab_veiculos.tam] = v;
      tab_veiculos.tam++;
    }
}
  fclose(arq);
  return tab_veiculos;
}

t_tab_p loadTabP(char filename[]){
  FILE* arq = fopen(filename, "rt");

  t_item_p p;
  t_tab_p props;
  props.tam = 0;

  if(fscanf(arq, "%[^,],%[^,],%[^,],%[^,\n]\n", p.cpf, p.nome, p.email, p.celular) == 4){
    while(fscanf(arq, "%[^,],%[^,],%[^,],%[^,\n]\n", p.cpf, p.nome, p.email, p.celular) == 4){
      props.v_proprietarios[props.tam] = p;
      props.tam++;
    }
  }
  return props;
}

t_tab_m loadTabM(char filename[]){
  t_tab_m tab_multas;
  t_item_m m;
  tab_multas.tam=0;
  char valor[16];
  FILE* arq = fopen(filename, "rt");
  while(fscanf(arq, "%[^,],%[^,],%[^,\n]\n", 
    m.placa, m.data, valor) == 3){
    m.valor = atof(valor);
    tab_multas.v_multas[tab_multas.tam] = m;
    tab_multas.tam++;
  }
  fclose(arq);
  return tab_multas;
}

void fazRelatorio(t_tab_v tv, t_tab_p tp, t_tab_m tm){  
  puts("RELATÓRIO VALOR TOTAL (R$) E QUANTIDADE DE MULTAS POR PROPRIETARIO\n");

  char bi[32],si[32] = {0};
  double soma_multas_bi = 0.0;
  double soma_multas_si = 100000000000000000;
  long int q_multas_bi = {0};
  long int q_multas_si = 100000000000000000;


  t_tab_v tabela_veiculos;
  tabela_veiculos.tam = 0;
  t_tab_m tabela_multas;
  tabela_multas.tam = 0;


  char cpf[16] = "";
  char placa[8] = "";

  for(int i = 0; i<tp.tam; i++){

    tabela_veiculos.tam = 0;
    
    float soma_multa = 0.0;
    long int q_multas = 0;
    
    strcpy(cpf, tp.v_proprietarios[i].cpf);

    for(int j = 0; j<tv.tam; j++){
      if (strcmp(cpf, tv.v_veiculos[j].cpf)==0){
        tabela_veiculos.v_veiculos[tabela_veiculos.tam] = tv.v_veiculos[j];
        tabela_veiculos.tam++;
      }
    }


    for(int j = 0; j < tabela_veiculos.tam; j++) {
      strcpy(placa, tabela_veiculos.v_veiculos[j].placa);

      for(int n = 0; n < tm.tam; n++) {
        if (strcmp(placa, tm.v_multas[n].placa) == 0) {
            soma_multa += tm.v_multas[n].valor;
            q_multas++;
        }
      }
    }

    if(soma_multa > soma_multas_bi){
      soma_multas_bi = soma_multa;
      strcpy(bi, tp.v_proprietarios[i].nome);
      q_multas_bi = q_multas;
    }

    if(soma_multa < soma_multas_si){
      soma_multas_si = soma_multa;
      strcpy(si, tp.v_proprietarios[i].nome);
      q_multas_si = q_multas;
    }

    printf("%-32s %-10.2lf %3li multas\n", tp.v_proprietarios[i].nome, soma_multa, q_multas);

    soma_multa = 0;
    q_multas = 0;

  }

  printf("\nMAIOR INFRATOR %s, %lf %li multa(s)\n", bi, soma_multas_bi, q_multas_bi);
  printf("MENOR INFRATOR %s, %lf %li multa(s)\n", si, soma_multas_si, q_multas_si);
}


int main(){
  char bd1[64] = "./tabveiculos.txt";
  char bd2[64] = "./tabproprietarios.txt";
  char bd3[64] = "./tabmultas.txt";

  t_tab_v tab_veiculos;
  t_tab_p tab_proprietarios;
  t_tab_m tab_multas;

  tab_veiculos = loadTabV(bd1);
  tab_proprietarios = loadTabP(bd2);
  tab_multas = loadTabM(bd3);

  fazRelatorio(tab_veiculos, tab_proprietarios, tab_multas);

  return 0;
}