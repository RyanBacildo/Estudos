#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {int lat, lon;} tcoords;

/*
int main(void){

  tcoords coords[500];
  tcoords *ptc;
  void *pc;

  FILE *arq;

  arq = fopen("./coords.txt", "rt");
    if(arq == NULL){
    puts("Erro, arquivo não encontrado. Encerrando o programa!!");
    return -1;

  return 0;
}
  fgets()
*/

tcoords *str_to_struct(char s[]){
  tcoords *st = (tcoords *)malloc(sizeof(tcoords));
  
  const char sep[2] = ",";
  char *pedaco;
  
  pedaco = strtok(s, sep);
  st->lat=atoi(pedaco);
  pedaco = strtok(NULL,sep);
  st->lon=atoi(pedaco);
    
  
  return st;
}

int main(void){
  FILE *arq = fopen("./coords.txt", "rt");
  char linha[25];
  int indice = 0;

  tcoords *vet[500];

  //BOA PRÁTICA
  for (int i=0; i< 500; i++)
    vet[i] = NULL;

  fgets(linha,32,arq);
    while(!feof(arq)){
    linha[strlen(linha)-1] = "\0";

    vet[indice++] = str_to_struct(linha);
    fgets(linha,32,arq);
    }

  indice = 0;

  while ((vet[indice] != NULL) && (indice < 500));
  {
    printf("%d,%d\n", vet[indice]->lat,vet[indice]->lon);
    indice++;
    }

  fclose(arq);
  
}