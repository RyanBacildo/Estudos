#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char id[4];
  char nome[64];
  char categoria[32];
  char marca[32];
  float preco;
  int garantia;
  int quantidade;
} t_item;

typedef struct {
  int tam;
  t_item v_itens[100];
}t_tabela;

t_tabela loadTab(char filename[]){
  t_tabela tab_itens;
  tab_itens.tam=0;

  t_item item;

  FILE* arq = fopen(filename, "rt");

  char preco[64], garantia[64], quantidade[64];
  
  if(fscanf(arq, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", 
    item.id, item.nome, item.categoria, item.marca, preco, garantia, quantidade) == 7){

    while(fscanf(arq, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^,\n]\n", item.id, item.nome, item.categoria, item.marca, preco, garantia, quantidade) == 7){
      item.preco = atof(preco);
      item.garantia = atoi(garantia);
      item.quantidade = atoi(quantidade);
      
      tab_itens.v_itens[tab_itens.tam] = item;
      tab_itens.tam++;
    }
}
  fclose(arq);
  return tab_itens;
}

void fazRelatorio(t_tabela tab){
  puts("RELATÓRIO TOTAL EM ESTOQUE POR MARCA (R$ E QUANT. TOTAIS)\n");

  t_tabela tabela;
  tabela.tam=0;
  char marca[32]={0};

  char maior[32], menor[32] = {0};
  double soma_estoque_maior = 0.0;
  double soma_estoque_menor = 100000000000000000;

  int q_itens = 0;
  
  for(int i=0;i<tab.tam;i++){
    
    //Leio a marca para comparar
    q_itens = 0;
    double soma_estoque = 0;
    int total_estoque = 0;
    
    strcpy(marca,tab.v_itens[i].marca);

    //No caso da primeira leitura
    if(tabela.tam == 0){
      for(int j=0;j<tab.tam-1;j++){
        if (strcmp(marca, tab.v_itens[j].marca)==0){
          int total_estoque = 0;
          total_estoque = (tab.v_itens[j].quantidade)*(tab.v_itens[j].preco);
          soma_estoque+=total_estoque;
          q_itens++;
        }
      }
      printf("%s %lf %d itens", tab.v_itens[i].marca, soma_estoque, q_itens);
      if (soma_estoque>soma_estoque_maior){
        soma_estoque_maior = soma_estoque;
        strcpy(maior,tabela.v_itens[i].marca);
      }

      if (soma_estoque<soma_estoque_menor){
        soma_estoque_menor = soma_estoque;
        strcpy(menor,tabela.v_itens[i].marca);
      }
    } 
    
    //A partir da segunda leitura 
    else {
      //Avalia se o item anterior é da mesma marca
      //Caso seja
      if (strcmp(tab.v_itens[i-1].marca,marca)==0){
        total_estoque = (tab.v_itens[i].quantidade)*(tab.v_itens[i].preco);
        soma_estoque+=total_estoque;
        q_itens++;
      } 
      //Caso não seja
      else {
        for(int j=0;j<tab.tam-1;j++){
          if (strcmp(marca, tab.v_itens[j].marca)==0){
            int total_estoque = 0;
            total_estoque = (tab.v_itens[j].quantidade)*(tab.v_itens[j].preco);
            soma_estoque+=total_estoque;
            q_itens++;
          }
        printf("%s %lf %d itens", tab.v_itens[i].marca, soma_estoque, q_itens);
      }
      
    if (soma_estoque>soma_estoque_maior){
      soma_estoque_maior = soma_estoque;
      strcpy(maior,tabela.v_itens[i].marca);
    }

    if (soma_estoque<soma_estoque_menor){
      soma_estoque_menor = soma_estoque;
      strcpy(menor,tabela.v_itens[i].marca);
    }
    
  }
   
  
  printf("\nMAIOR TOTAL EM ESTOQUE: %32s, %7.2lf\n", maior, soma_estoque_maior);
  printf("MAIOR TOTAL EM ESTOQUE: %32s, %7.2lf\n", menor, soma_estoque_menor);
}
  }
}

int main(){
  char bd[32] = "./tabti.txt";
  t_tabela tab_itens;
  tab_itens = loadTab(bd);
  fazRelatorio(tab_itens);
  return 0;
}