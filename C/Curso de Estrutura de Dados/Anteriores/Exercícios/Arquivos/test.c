#include <stdio.h>
#include <string.h>

//Definindo Struckts
typedef struct {
  char placa[10];
  char modelo[20];
  char km[10];
} tcarros;

typedef struct {
  char nmarca[20];
  tcarros bd_carros[50];
  int num;
} tmarcas;
//...

//Atribuindo Carro
tcarros cad_carro(char p1[], char m1[], char k1[]) {
  tcarros carro;
  
  strcpy(carro.placa,p1);
  strcpy(carro.modelo,m1);
  strcpy(carro.km,k1);

  return carro;
}
//...

//Atribuindo Marca
tmarcas cad_marca(char n1[], tcarros c1, int i) {
  tmarcas marca;
  
  strcpy(marca.nmarca,n1);
  marca.bd_carros[i]= c1;

  return marca;
}
//...

//Verica Carro

//

//Main
int main(void) {
  tcarros carro;
  tcarros bd_carros[50];
  tmarcas marca;
  char placa[30], modelo[30], km[30], nmarca[30];
  int num;
  
  num = 0;

  FILE *arq;
  arq = fopen("bdveiculos.txt", "rt");

  if (arq == NULL) {
    printf("Arquivo não encontrado!");
  }

  else {
    
    fgets(placa, 10, arq);
    
    while (!feof(arq)) {
      
      fgets(modelo, 20, arq);
      fgets(nmarca, 20, arq);
      fgets(km, 10, arq);
      carro = cad_carro(placa, modelo, km);
      marca = cad_marca(nmarca,carro,num);
      
      vc_carros(marca,carro,bd_carros);
      
      num++;
      fgets(placa, 10, arq);
    }
  }
  return 0;
}
//...