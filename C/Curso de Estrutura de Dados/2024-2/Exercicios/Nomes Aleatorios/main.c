#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sorteia_nome(char vetA[][20], char vetB[][20], int num){
  char nome_completo[20][20];
  int p_nome = 0;
  int v_sobrenomes[16] = {0};
  int aux;
  int count = 0;

  for(int i=0;i<1;i++){
    p_nome = rand() % 20;
    strcpy(nome_completo[0], vetA[p_nome]);
    if (num>1){
      for(int j=0;j<num-1;j++){
      aux = rand() % 15;
        if(j!=0){
          count =0;
          while(count < 15){
            if (aux == v_sobrenomes[count]){
              aux = rand() % 15;
            }
            count++;
          } 
          v_sobrenomes[j] = aux;
        }
      strcpy(nome_completo[j+1],vetB[v_sobrenomes[j]]);
      }
    }
  }
  for(int i=0;i<num;i++){
    printf("%s ",nome_completo[i]);  
  }
}

int main() {
  char nome[20][20] = {
  "Miguel", "Gael", "Maria Alice", "Arthur", "Helena", "Heitor", "Alice", "Theo", "Laura", "Davi", "Samuel", "Bernardo", "Gabriel", "Ravi", "João Miguel", "Noah", "Maria Cecilia", "Cecilia", "Maite", "Heloisa"
};
  char sobrenome[15][20] = {
  "Almeida", "Alves", "Andrade", "Barbosa", "Barros", "Batista", "Borges", "Campos", "Cardoso", "Carvalho", "Castro", "Costa", "Dias", "Duarte", "Freitas"
};

  int valor = 100;
  
  while(valor>=16 || valor<= 0){
    valor = 100;
    puts("Digite o número para o tamanho do nome composto (máx: 16) : ");
    scanf("%d", &valor);
  }
  sorteia_nome(nome, sobrenome, valor);
  
  return 0;
}