#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadmatriz.h"

typedef struct line{
    char ele1[3];
    char ele2[2];
    char ele3[3];
}t_linha;

void exibir_matriz(tadmatriz mat) {
    printf("%d %d\n", mat->linhas, mat->colunas);
    for (int i = 0; i < mat->linhas; i++) {
        for (int j = 0; j < mat->colunas; j++) {
            printf("%8d ", (int)get_elem(mat, i, j));
        }
        printf("\n");
    }
}
/*
tadmatriz processa_linha(const char *linha){
    tadmatriz x,y;
    int op, trans = 0;
    t_linha op_linha;
    
    if(sscanf(linha, "%[^ ] %[^ ] %[^ ]", op_linha.ele1, op_linha.ele2, op_linha.ele3)==3){
        x = carrega(op_linha.ele1[-1]);
        
        if(op_linha.ele1[0] == '-' || op_linha.ele1[0] == 'T'){
            if (op_linha.ele1[0] == '-')
                x = neg(x);
            if(op_linha.ele1[0] == 'T')
                x = transp(x);
        }
        
        char oper[2] = op_linha.ele2;

        if( op_linha.ele2 == '+')
            op = 1;
            
        if( op_linha.ele2 == '-')
            op = 2;
        
        if( op_linha.ele2 == 'x')
            op = 3;
        
        if(op_linha.ele3[0] == '-' || op_linha.ele3[0] == 'T'){
            if (op_linha.ele3[0] == '-')
                y = neg(y);
            if(op_linha.ele3[0] == 'T')
                y = transp(y);
        }
        
        if (op == 1)
            soma(x,y);
        
        if (op == 2){
            y = neg(y);
            soma(x,y);
        }
         
        if (op == 3)
            multi(x,y);

    }


}
*/
void cria_arq(const char *linha){
    FILE *novo_arquivo = fopen(linha, "wt");
        if (novo_arquivo) {
            printf("Arquivo '%s' criado.\n", linha);

            processa_linha(linha);

            fclose(novo_arquivo);
        } else {
            printf("Erro ao criar o arquivo '%s'.\n", linha);
        }
}

void processa_matops(const char *file) {
    FILE *arq = fopen(file, "rt");
    if (!arq) {
        printf("Erro ao abrir o arquivo %s\n", file);
        return;
    }

    char linha[256];
    while (fgets(linha, sizeof(linha), arq)) {

        if (linha[strlen(linha) - 1] == '\n') {
            linha[strlen(linha) - 1] = '\0';
        }

        cria_arq(linha);
    }

    fclose(arq);
}

int main() {
    FILE *arq = fopen("matops.txt", "rt");
    if (!arq) {
        printf("Erro ao abrir o arquivo matops.txt\n");
        return 1;
    }

    char operacao[256];
    tadmatriz A, B, C, D;

    A = carrega("A.txt");
    B = carrega("B.txt");
    C = carrega("C.txt");
    D = carrega("D.txt");

    if (A && B && C && D) {
        exibir_matriz(A);
        exibir_matriz(B);
        exibir_matriz(C);
        exibir_matriz(D);
    }

    fclose(arq);

    processa_matops("matops.txt");

    //criar_arquivos("matops.txt");

    return 0;
}