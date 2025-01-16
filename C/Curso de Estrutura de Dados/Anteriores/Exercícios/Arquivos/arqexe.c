#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
#include <stdio.h>
#include <string.h>

#define MAX_VEICULOS 200

typedef struct {
    char marca[50];
    char modelo[50];
    int ano;
} TVEICULO;

// Função para carregar veículos do arquivo e retornar o número de veículos
int carrega_veics(TVEICULO veiculos[], const char *nome_arquivo) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        perror("Erro ao abrir o arquivo");
        return -1;
    }

    int num_veiculos = 0;
    while (fscanf(arquivo, "%s %s %d", veiculos[num_veiculos].marca, veiculos[num_veiculos].modelo, &veiculos[num_veiculos].ano) != EOF) {
        num_veiculos++;
        if (num_veiculos >= MAX_VEICULOS) {
            printf("Limite máximo de veículos atingido (%d).\n", MAX_VEICULOS);
            break;
        }
    }

    fclose(arquivo);
    return num_veiculos;
}

// Função para filtrar veículos por marca e escrever em um arquivo
void filtro(TVEICULO veiculos[], int num_veiculos, char marca_desejada[]) {
    char nome_arquivo[100];
    snprintf(nome_arquivo, sizeof(nome_arquivo), "%s.txt", marca_desejada);
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo");
        return;
    }

    for (int i = 0; i < num_veiculos; i++) {
        if (strcmp(veiculos[i].marca, marca_desejada) == 0) {
            fprintf(arquivo, "Marca: %s\nModelo: %s\nAno: %d\n\n", veiculos[i].marca, veiculos[i].modelo, veiculos[i].ano);
        }
    }

    fclose(arquivo);
}

int main() {
    TVEICULO veiculos[MAX_VEICULOS];
    int num_veiculos = carrega_veics(veiculos, "bdveiculos.txt");
    if (num_veiculos == -1) {
        return 1; // Erro ao carregar veículos
    }

    char marcas[][50] = {"FORD", "TOYOTA", "CITROEN", "NISSAN", "VOLKSWAGEN", "RENAULT"};
    int num_marcas = sizeof(marcas) / sizeof(marcas[0]);

    for (int i = 0; i < num_marcas; i++) {
        filtro(veiculos, num_veiculos, marcas[i]);
    }

    return 0;
}





typedef struct {
 char placa[10];
 char modelo[32];
 char marca[32];
 int km;
} tveiculo;

void print_veiculo(tveiculo tv){
  printf("%s,%s,%s,%d\n",tv.placa,tv.modelo,tv.marca,tv.km);
}

int main(){
  FILE *arq;
  char buffer[20];
  tveiculo v;
  
  arq = fopen("./bdveiculos.txt","rt");

  fscanf(arq,"%s",buffer);
  strcpy(v.placa,buffer);

  fscanf(arq,"%s",buffer);
  strcpy(v.modelo,buffer);

  fscanf(arq,"%s",buffer);
  strcpy(v.marca,buffer); 

  fscanf(arq,"%d",&v.km);

  print_veiculo(v);

  fclose(arq);

  return 0;
}

typedef struct {
 char placa[10];
 char modelo[32];
 char marca[32];
 int km;
} tveiculo;

void print_veiculo(tveiculo tv){
  printf("%s,%s,%s,%d\n",tv.placa,tv.modelo,tv.marca,tv.km);
}

int main(){
  FILE *arq;
  tveiculo v;

  strcpy(v.placa,"YHG-1234");
  strcpy(v.modelo,"Versa");
  strcpy(v.marca,"NISSAN");
  v.km = 123456;

  print_veiculo(v);
  
  arq = fopen("./teste.txt","wt");
  fprintf(arq,"%s,%s,%s,%d\n",v.placa,v.modelo,v.marca,v.km);
  fclose(arq);

  puts("Concluído!!");

  return 0;
}

int main() {
  FILE *arq;
  char s[64];

  arq = fopen("./bdveiculos.txt","rt");
  if(arq == NULL)
    puts("Erro, arquivo não encontrado. Encerrando o programa!!");
  else {
    fgets(s,60,arq);
    while(!feof(arq)){
      s[strlen(s)-1] = '\0';
      printf("%s\n",s);
      fgets(s,60,arq);     
    } // while ..

    puts("Processamento concluído!!!");  
  } // else ..
  




  return 0;
}


typedef struct {
 char placa[10];
 char modelo[32];
 char marca[32];
 int km;
} tveiculo;

void carrega_veics(char arquivo){
  FILE *arq;
  char buffer[20];
  tveiculo v;
  
  arq = fopen("./bdveiculos.txt","rt");

  fscanf(arq,"%s",buffer);
  strcpy(v.placa,buffer);

  fscanf(arq,"%s",buffer);
  strcpy(v.modelo,buffer);

  fscanf(arq,"%s",buffer);
  strcpy(v.marca,buffer); 

  fscanf(arq,"%d",&v.km);

  print_veiculo(v);

  fclose(arq);
}

void filtro(){

  
}

int main(){
  char arquivo[10];
  arquivo = ["./bdveiculos.txt"];

  return 0;
}





#include <stdio.h>
#include <string.h>

typedef struct {
    char placa[10];
    char modelo[32];
    char marca[32];
    int km;
} tveiculo;

void print_veiculo(tveiculo tv) {
    printf("%s,%s,%s,%d\n", tv.placa, tv.modelo, tv.marca, tv.km);
}

void carrega_veics(tveiculo veiculos[], int *num_veiculos, const char *nome_arquivo) {
    FILE *arq;
    arq = fopen(nome_arquivo, "rt");

    if (arq == NULL) {
        printf("Erro, arquivo não encontrado. Encerrando o programa!!\n");
        return;
    }

    *num_veiculos = 0;

    while (fscanf(arq, "%s %s %s %d", veiculos[*num_veiculos].placa, veiculos[*num_veiculos].modelo, veiculos[*num_veiculos].marca, &veiculos[*num_veiculos].km) != EOF) {
        (*num_veiculos)++;
        if (*num_veiculos >= 200) {
            printf("Limite máximo de veículos atingido (200).\n");
            break;
        }
    }

    fclose(arq);
}

void filtro(tveiculo veiculos[], int num_veiculos, const char marca_desejada[]) {
    char nome_arquivo[100];
    snprintf(nome_arquivo, sizeof(nome_arquivo), "./%s.txt", marca_desejada);
    FILE *arquivo = fopen(nome_arquivo, "wt");

    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo");
        return;
    }

    for (int i = 0; i < num_veiculos; i++) {
        if (strcmp(veiculos[i].marca, marca_desejada) == 0) {
            fprintf(arquivo, "%s %s %s %d\n", veiculos[i].placa, veiculos[i].modelo, veiculos[i].marca, veiculos[i].km);
        }
    }

    fclose(arquivo);
}

int main() {
    tveiculo veiculos[200];
    int num_veiculos = 0;

    carrega_veics(veiculos, &num_veiculos, "./bdveiculos.txt");

    if (num_veiculos > 0) {
        char marcas[][32] = {"FORD", "TOYOTA", "CITROEN", "NISSAN", "VOLKSWAGEN", "RENAULT"};
        int num_marcas = sizeof(marcas) / sizeof(marcas[0]);

        for (int i = 0; i < num_marcas; i++) {
            filtro(veiculos, num_veiculos, marcas[i]);
        }
    }

    puts("Concluído!!");
    return 0;
}

*/

#include <stdio.h>
#include <string.h>

typedef struct {
    char placa[10];
    char modelo[32];
    char marca[32];
    int km;
} tveiculo;

void print_veiculo(tveiculo tv) {
    printf("%s,%s,%s,%d\n", tv.placa, tv.modelo, tv.marca, tv.km);
}

void carrega_veics(tveiculo veiculos[], int *num_veiculos, const char *nome_arquivo) {
    FILE *arq;
    arq = fopen(nome_arquivo, "rt");

    if (arq == NULL) {
        printf("Erro, arquivo não encontrado. Encerrando o programa!!\n");
        return;
    }

    *num_veiculos = 0;

    while (fscanf(arq, "%s %s %s %d", veiculos[*num_veiculos].placa, veiculos[*num_veiculos].modelo, veiculos[*num_veiculos].marca, &veiculos[*num_veiculos].km) != EOF) {
        (*num_veiculos)++;
        if (*num_veiculos >= 200) {
            printf("Limite máximo de veículos atingido (200).\n");
            break;
        }
    }

    fclose(arq);
}

void filtro(tveiculo veiculos[], int num_veiculos, const char marca_desejada[]) {
    char nome_arquivo[100];
    snprintf(nome_arquivo, sizeof(nome_arquivo), "./%s.txt", marca_desejada);
    FILE *arquivo = fopen(nome_arquivo, "wt");

    if (arquivo == NULL) {
        perror("Erro ao criar o arquivo");
        return;
    }

    for (int i = 0; i < num_veiculos; i++) {
        if (strcmp(veiculos[i].marca, marca_desejada) == 0) {
            fprintf(arquivo, "%s %s %s %d\n", veiculos[i].placa, veiculos[i].modelo, veiculos[i].marca, veiculos[i].km);
        }
    }

    fclose(arquivo);
}

int main() {
    tveiculo veiculos[200];
    int num_veiculos = 0;

    carrega_veics(veiculos, &num_veiculos, "./bdveiculos.txt");

    if (num_veiculos > 0) {
        char marcas[][32] = {"FORD", "TOYOTA", "VOLKSWAGEN", "RENAULT"};
        int num_marcas = sizeof(marcas) / sizeof(marcas[0]);

        for (int i = 0; i < num_marcas; i++) {
            filtro(veiculos, num_veiculos, marcas[i]);
        }
    }

    puts("Concluído!!");
    return 0;
}
