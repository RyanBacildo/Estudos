#include <stdio.h>
#include <stdlib.h>
#include "tadlista.h"

int main(){
    Lista lst = criaLista();
    int *pnum;
    char s[8];

    FILE *arq = fopen("numeros.txt", "rt");
    
    while(!feof(arq)){
        fgets(s,7,arq);
        pnum = (int *)malloc(sizeof(int));
        *pnum = atoi(s);
        appendLista(lst,pnum);
    }
    fclose(arq);

    //Resolver o problema

    return 0;
}