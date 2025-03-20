#include <stdio.h>
#include <stdlib.h>
#include "tadlista.h"

typedef struct {
    char nome[128];
    char sigla[8];
    char regiao[16];
} Universidade;

Lista cadastra_lista(char fileName[]){
    FILE *arq=fopen(fileName, "rt");
    Lista ufs = criaLista();
    Universidade *uf = (Universidade *)malloc(sizeof(Universidade));

    while(!feof){
        if (fscanf(arq,"%[^,],[^,],[^,\n]\n", uf->nome, uf->sigla, uf->regiao)==3){
            appendLista(ufs, uf);
            ufs->tamlista++;
        printf("%s",uf->sigla);
        }
    }

    fclose(arq);

    return ufs;
}

int main(){
    char arquivo[8] = "ufs.txt";
    Lista lista_ufs = cadastra_lista(arquivo);
    return 0;
}

