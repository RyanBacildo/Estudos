#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadlista.h"

typedef struct tipo_entrada{
    char chave[32];
    t_dado valor;
} *t_entrada;

typedef struct t_dict{
    Lista *vet_dados;
    int tam_vet_dados;
} *Dict; 

Dict criaDict(int quant_Dados){
    float FC = 0.75;
    int tam_vet = quant_Dados/FC;
    Dict d = (Dict)malloc(sizeof (struct t_dict));

    d->tam_vet_dados = tam_vet;
    
    d->vet_dados =(Lista)malloc(tam_vet * sizeof(Lista));
    
    for(int i=0; i<tam_vet;i++){
        d->vet_dados[i] = NULL;
    }

    return d;
}

Dict adiciona(Dict taddic, char *k, t_dado valor){
    int cod_hash = fh(k);
    int pos = cod_hash % taddic->tam_vet_dados;

    if(taddic->vet_dados[pos]==NULL){
        taddic->vet_dados[pos] = criaLista();
    }

    t_entrada entrada = (t_entrada)malloc(sizeof(struct tipo_entrada));
    strcpy(entrada->chave, k);
    entrada->valor = valor;

    appendLista(taddic->vet_dados[pos],entrada);

    return taddic;
}

void printLenListas(Dict taddic){
    for (int i=0; i<taddic->tam_vet_dados; i++){
        if(taddic->vet_dados[i] != NULL){
            printf("%d, %d\n", i, lenlista(taddic->vet_dados[i] ));
        }
    }
}