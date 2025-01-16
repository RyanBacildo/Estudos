#include "tadmatriz.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void gera_matriz(char *nome_arq,char p1[], char p2[], char p3[]){

  int l, c = 0;
  char linha[100];
  FILE *A = fopen("A.txt", "rt");
  while(fgets(linha, sizeof(linha), A) != NULL){
    l++;
    if (l == 1) {
      for(int i = 0; linha[i] != '\0'; i++){
        if(linha[i] == ' ' && linha [i] != '\t'){
          c++;
        }
      }
    }
  }
  tadmat mA = cria_mat(l, c);
  
  tadmat mbuffer = carrega_mat("A.txt");

  for (int i=0; i<l; i++){

  }
  
  fclose(A);

  FILE *B = fopen("B.txt", "rt");

  fclose(B);
  FILE *C = fopen("C.txt", "rt");

  fclose(C);
  FILE *D = fopen("D.txt", "rt");

  fclose(D);




  

  
  char nome_p[15];
  char buffer[15];
  char aux[30] = "\0";

  // AVALIA SINAIS P1
  if (p1[0] == '-') {
    strcpy(buffer, "menos");
  } else if (p1[0] == 'T') {
    strcpy(buffer, "transp");
  } else {
    if (p1[0] == 'A') {
      strcpy(nome_p, "A");
      strcpy(buffer, "NULL");
    } else if (p1[0] == 'B') {
      strcpy(nome_p, "B");
      strcpy(buffer, "NULL");
    } else if (p1[0] == 'C') {
      strcpy(nome_p, "C");
      strcpy(buffer, "NULL");
    } else if (p1[0] == 'D') {
      strcpy(nome_p, "D");
      strcpy(buffer, "NULL");
    } else {
      strcpy(nome_p, p1);
      strcpy(buffer, "NULL");
    }
  }

  
  
  if (p1[1] == 'A') {
    strcpy(nome_p, "A");
  } else if (p1[1] == 'B') {
    strcpy(nome_p, "B");
  } else if (p1[1] == 'C') {
    strcpy(nome_p, "C");
  } else if (p1[1] == 'D') {
    strcpy(nome_p, "D");
  } else {
    strcpy(nome_p, p1);
  }

  // ESCREVE EM AUX
  if (strcmp(buffer, "NULL") != 0) {
    if (strlen(aux) > 0) {
      strcat(aux, buffer);
    } else {
      strcpy(aux, buffer);
    }
  }
  if (strlen(nome_p) > 0) {
    if (strlen(aux) > 0) {
      strcat(aux, nome_p);
    } else {
      strcpy(aux, nome_p);
    }
  }

  // AVALIA SINAIS P2
  if (strcmp(p2, "-") == 0) {
    strcpy(buffer, "menos");
  } else if (strcmp(p2, "+") == 0) {
    strcpy(buffer, "mais");
  } else if (strcmp(p2, "x") == 0) {
    strcpy(buffer, "vezes");
  } else {
    strcpy(buffer, "NULL");
  }

  // ESCREVE EM AUX
  if (strcmp(buffer, "NULL") != 0) {
    if (strlen(aux) > 0) {
      strcat(aux, buffer);
    } else {
      strcpy(aux, buffer);
    }
  }

  // AVALIA SINAIS P3
  if (p3[0] == '-') {
    strcpy(buffer, "menos");
  } else if (p3[0] == 'T') {
    strcpy(buffer, "transp");
  } else {
    if (p3[0] == 'A') {
      strcpy(nome_p, "A");
      strcpy(buffer, "NULL");
    } else if (p3[0] == 'B') {
      strcpy(nome_p, "B");
      strcpy(buffer, "NULL");
    } else if (p3[0] == 'C') {
      strcpy(nome_p, "C");
      strcpy(buffer, "NULL");
    } else if (p3[0] == 'D') {
      strcpy(nome_p, "D");
      strcpy(buffer, "NULL");
    } else {
      strcpy(nome_p, p3);
      strcpy(buffer, "NULL");
    }
  }
  if (p3[1] == 'A') {
    strcpy(nome_p, "A");
  } else if (p3[1] == 'B') {
    strcpy(nome_p, "B");
  } else if (p3[1] == 'C') {
    strcpy(nome_p, "C");
  } else if (p3[1] == 'D') {
    strcpy(nome_p, "D");
  } else {
    strcpy(nome_p, p3);
  }

  // ESCREVE EM AUX
  if (strcmp(buffer, "NULL") != 0) {
    if (strlen(aux) > 0) {
      strcat(aux, buffer);
    } else {
      strcpy(aux, buffer);
    }
  }
  if (strlen(nome_p) > 0) {
    if (strlen(aux) > 0) {
      strcat(aux, nome_p);
    } else {
      strcpy(aux, nome_p);
    }
  }
}

char *descrevep(char p1[], char p2[], char p3[]) {
  char *nome_arq = (char *)malloc(30 * sizeof(char));
  char nome_p[15];
  char buffer[15];
  char aux[30] = "\0";

  

  // AVALIA SINAIS P1
  if (p1[0] == '-') {
    strcpy(buffer, "menos");
  } else if (p1[0] == 'T') {
    strcpy(buffer, "transp");
  } else {
    if (p1[0] == 'A') {
      strcpy(nome_p, "A");
      strcpy(buffer, "NULL");
    } else if (p1[0] == 'B') {
      strcpy(nome_p, "B");
      strcpy(buffer, "NULL");
    } else if (p1[0] == 'C') {
      strcpy(nome_p, "C");
      strcpy(buffer, "NULL");
    } else if (p1[0] == 'D') {
      strcpy(nome_p, "D");
      strcpy(buffer, "NULL");
    } else {
      strcpy(nome_p, p1);
      strcpy(buffer, "NULL");
    }
  }
  if (p1[1] == 'A') {
    strcpy(nome_p, "A");
  } else if (p1[1] == 'B') {
    strcpy(nome_p, "B");
  } else if (p1[1] == 'C') {
    strcpy(nome_p, "C");
  } else if (p1[1] == 'D') {
    strcpy(nome_p, "D");
  } else {
    strcpy(nome_p, p1);
  }

  // ESCREVE EM AUX
  if (strcmp(buffer, "NULL") != 0) {
    if (strlen(aux) > 0) {
      strcat(aux, buffer);
    } else {
      strcpy(aux, buffer);
    }
  }
  if (strlen(nome_p) > 0) {
    if (strlen(aux) > 0) {
      strcat(aux, nome_p);
    } else {
      strcpy(aux, nome_p);
    }
  }

  // AVALIA SINAIS P2
  if (strcmp(p2, "-") == 0) {
    strcpy(buffer, "menos");
  } else if (strcmp(p2, "+") == 0) {
    strcpy(buffer, "mais");
  } else if (strcmp(p2, "x") == 0) {
    strcpy(buffer, "vezes");
  } else {
    strcpy(buffer, "NULL");
  }

  // ESCREVE EM AUX
  if (strcmp(buffer, "NULL") != 0) {
    if (strlen(aux) > 0) {
      strcat(aux, buffer);
    } else {
      strcpy(aux, buffer);
    }
  }

  // AVALIA SINAIS P3
  if (p3[0] == '-') {
    strcpy(buffer, "menos");
  } else if (p3[0] == 'T') {
    strcpy(buffer, "transp");
  } else {
    if (p3[0] == 'A') {
      strcpy(nome_p, "A");
      strcpy(buffer, "NULL");
    } else if (p3[0] == 'B') {
      strcpy(nome_p, "B");
      strcpy(buffer, "NULL");
    } else if (p3[0] == 'C') {
      strcpy(nome_p, "C");
      strcpy(buffer, "NULL");
    } else if (p3[0] == 'D') {
      strcpy(nome_p, "D");
      strcpy(buffer, "NULL");
    } else {
      strcpy(nome_p, p3);
      strcpy(buffer, "NULL");
    }
  }
  if (p3[1] == 'A') {
    strcpy(nome_p, "A");
  } else if (p3[1] == 'B') {
    strcpy(nome_p, "B");
  } else if (p3[1] == 'C') {
    strcpy(nome_p, "C");
  } else if (p3[1] == 'D') {
    strcpy(nome_p, "D");
  } else {
    strcpy(nome_p, p3);
  }

  // ESCREVE EM AUX
  if (strcmp(buffer, "NULL") != 0) {
    if (strlen(aux) > 0) {
      strcat(aux, buffer);
    } else {
      strcpy(aux, buffer);
    }
  }
  if (strlen(nome_p) > 0) {
    if (strlen(aux) > 0) {
      strcat(aux, nome_p);
    } else {
      strcpy(aux, nome_p);
    }
  }

  strcpy(nome_arq, aux);
  strcat(nome_arq, ".txt");
  return nome_arq;
  
}

int main(void) {
  char arquivo[50] = "matops.txt";
  FILE *arq = fopen(arquivo, "rt");

  char p1[3], p2[3], p3[3];
  char *narq;

  while (fscanf(arq, "%s %s %s", p1, p2, p3) == 3) {
    narq = descrevep(p1, p2, p3);
    // CM
    gera_matriz(narq, p1, p2, p3);
    

    // FM
    free(narq);
  }

  fclose(arq);
  return 0;
}
