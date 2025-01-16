#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char placa[30];
  char marca[30]; 
  char modelo[30];
  int km;
  } t_veiculo;

void print(t_veiculo lst[]) {
  int j=0;
  char x[5] = "NULL";

  while (lst[j].placa !=  x){
    printf("Placa: %s\n", lst[j].placa);
    printf("Marca: %s\n", lst[j].marca);
    printf("Modelo: %s\n", lst[j].modelo);
    printf("Km: %d\n", lst[j].km);
  }
  
}

t_veiculo cad_veiculo(char placa[], char marca[], char modelo[], char skm[]){
  t_veiculo veiculo;
  
  strcpy(veiculo.placa, placa);
  strcpy(veiculo.marca, marca);
  strcpy(veiculo.modelo, modelo);
  veiculo.km = atoi(skm);

  return veiculo;
}
  
int main(void){
  FILE *arq = fopen("./bdveiculos.c", "rt");
  
  char placa[30];
  char marca[30]; 
  char modelo[30];
  char skm[30];
  
  int i = 0;
  int *pi;
  
  t_veiculo lst[500];
  
  for (int i = 0; i<=500; i++){
  strcpy(lst[i].placa, "NULL");
  strcpy(lst[i].marca, "NULL");
  strcpy(lst[i].modelo, "NULL");
  lst[i].km = -1;
  }
  
  fscanf(arq, "%s", placa);
  while(!feof(arq)){
    fscanf(arq, "%s", marca);
    fscanf(arq, "%s", modelo);
    fscanf(arq, "%s", skm);
    
    lst[i] = cad_veiculo(placa, marca, modelo, skm);
    i++;
    
    fscanf(arq, "%s", placa);

    print(lst);
    }

  pi= &i;
  return 0;
}