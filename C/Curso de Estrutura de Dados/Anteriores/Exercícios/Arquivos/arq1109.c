#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_MARCAS 64

typedef struct {
  char placa[10];
  char modelo[15];
  int km;
} veiculos;

typedef struct {
  char nmarca[15];
  veiculos carros[MAX_MARCAS];
  int n;
} marcas;

int main(){
  marcas bd[MAX_MARCAS];
  veiculos veiculo;
  marcas marca;

  int pos;
  FILE *arq;
  char buffer[60];

  arq = fopen("./bdveiculos.txt","rt");
  if(arq == NULL){
    puts("Erro, arquivo não encontrado. Encerrando o programa!!");
    return -1;
  }
  else {
    pos = 0;
    
    fgets(placa,60,arq); // placa
    while(!feof(arq)){
      fgets(modelo,60,arq); // modelo
      fgets(marca,60,arq); // marca
      fgets(strkm,60,arq); // km

      veiculo = retorna_veiculo(placa,modelo,strkm);
      pormarca = pesquisamarca(bd,marca);

      if 
      
    } // while ..
    return pos;
  } // else ..
    
  
  return 0;
}