#include <stdio.h>
#include <string.h>

typedef struct {
  char placa[8];
  char marca[20];
  char modelo[20];
  char cpf[15];
} Veiculo;

typedef struct {
  int tam;
  Veiculo v_veiculos[64];
} t_veiculos;

typedef struct {
  char cpf[15];
  char nome[20];
  char email[50];
  char numero[20];
} Proprietario;

typedef struct {
  int tam;
  Proprietario v_proprietarios[64];
} t_proprietarios;

t_veiculos cria_tab_veiculos(char filename[]){
  t_veiculos tab_veiculos;
  tab_veiculos.tam=0;
  
  Veiculo v;
  
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

t_proprietarios cria_tab_proprietarios(char filename[]){
  FILE* arq = fopen(filename, "rt");
  
  Proprietario p;
  t_proprietarios props;
  props.tam = 0;
  
  if(fscanf(arq, "%[^,],%[^,],%[^,],%[^,\n]\n", p.cpf, p.nome, p.email, p.numero) == 4){
    while(fscanf(arq, "%[^,],%[^,],%[^,],%[^,\n]\n", p.cpf, p.nome, p.email, p.numero) == 4){
      props.v_proprietarios[props.tam] = p;
      props.tam++;
    }
  }
  return props;
}

void cria_tab_associacoes(t_proprietarios props, t_veiculos veics){
  t_veiculos tabela_veiculos;
  tabela_veiculos.tam = 0;
  char cpf[15] = "";

  for(int i = 0; i<props.tam; i++){
    tabela_veiculos.tam = 0;
    strcpy(cpf, props.v_proprietarios[i].cpf);

    printf("\nProprietario: %s\nEmail: %s\n", props.v_proprietarios[i].nome, props.v_proprietarios[i].email);
    
    for(int j = 0; j<veics.tam; j++){
      
      if (strcmp(cpf, veics.v_veiculos[j].cpf)==0){
        tabela_veiculos.v_veiculos[tabela_veiculos.tam] = veics.v_veiculos[j];
        tabela_veiculos.tam++;   
    
        printf("%s %s\n", tabela_veiculos.v_veiculos[tabela_veiculos.tam - 1].marca,tabela_veiculos.v_veiculos[tabela_veiculos.tam - 1].modelo);
      
      }
    }
  }
}

void print_veics(t_veiculos tab_veics){
  for(int i = 0; i<tab_veics.tam; i++){
    printf("|%s |%24s |%24s |%16s|\n", tab_veics.v_veiculos[i].placa, tab_veics.v_veiculos[i].marca, tab_veics.v_veiculos[i].modelo, tab_veics.v_veiculos[i].cpf);
  }
}

void print_props(t_proprietarios tab_props){
  for(int i = 0; i<tab_props.tam; i++){
    printf("|%s |%24s |%24s |%16s|\n", tab_props.v_proprietarios[i].cpf,tab_props.v_proprietarios[i].nome,tab_props.v_proprietarios[i].email,tab_props.v_proprietarios[i].numero);
  }
}

int main(){
  char bd1[32] = "./bdveiculos.txt";
  char bd2[32] = "./bdproprietarios.txt";

  t_proprietarios tab_props;
  t_veiculos tab_veics;

  tab_props = cria_tab_proprietarios(bd2);
  tab_veics = cria_tab_veiculos(bd1);
  
  //print_props(tab_props);
  //printf("\n DIVISÃO \n\n");
  //print_veics(tab_veics);
  cria_tab_associacoes(tab_props, tab_veics);
  return 0;
}