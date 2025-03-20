#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadlista.h"

typedef struct t_matriz {
    int linhas;
    int colunas;
    Lista *dados;
} *tadmatriz;

tadmatriz cria_mat(int qlinhas, int qcolunas) {
    tadmatriz mat = (tadmatriz)malloc(sizeof(struct t_matriz));
    mat->linhas = qlinhas;
    mat->colunas = qcolunas;
    mat->dados = (Lista*)malloc(qlinhas * sizeof(Lista));

    for (int i = 0; i < qlinhas; i++) {
        mat->dados[i] = new_lista();
        for (int j = 0; j < qcolunas; j++) {
            float *valor = (float*)malloc(sizeof(float));
            *valor = 0.0f;
            appendLista(mat->dados[i], valor);
        }
    }
    return mat;
}

void set_elem(tadmatriz tadA, int linha, int coluna, float valor) {
    if (linha < 0 || linha >= tadA->linhas || coluna < 0 || coluna >= tadA->colunas)
        return;

    Lista lista = tadA->dados[linha];
    float *antigo = (float*)removeLista(lista, coluna);
    free(antigo);

    float *novo = (float*)malloc(sizeof(float));
    *novo = valor;
    insereLista(lista, novo, coluna);
}

float get_elem(tadmatriz tadA, int linha, int coluna) {
    if (linha < 0 || linha >= tadA->linhas || coluna < 0 || coluna >= tadA->colunas)
        return 0.0f;

    t_dado elemento = elemLista(tadA->dados[linha], coluna);
    return elemento ? *((float*)elemento) : 0.0f;
}

int get_linhas(tadmatriz matA) {
    return matA->linhas;
}

int get_colunas(tadmatriz matA) {
    return matA->colunas;
}

tadmatriz soma(tadmatriz tadA, tadmatriz tadB) {
    if (tadA->linhas != tadB->linhas || tadA->colunas != tadB->colunas)
        return NULL;

    tadmatriz resultado = cria_mat(tadA->linhas, tadA->colunas);
    for (int i = 0; i < tadA->linhas; i++) {
        for (int j = 0; j < tadA->colunas; j++) {
            float val = get_elem(tadA, i, j) + get_elem(tadB, i, j);
            set_elem(resultado, i, j, val);
        }
    }
    return resultado;
}

tadmatriz multi(tadmatriz tadA, tadmatriz tadB) {
    if (tadA->colunas != tadB->linhas)
        return NULL;

    tadmatriz resultado = cria_mat(tadA->linhas, tadB->colunas);
    for (int i = 0; i < tadA->linhas; i++) {
        for (int j = 0; j < tadB->colunas; j++) {
            float soma = 0.0f;
            for (int k = 0; k < tadA->colunas; k++) {
                soma += get_elem(tadA, i, k) * get_elem(tadB, k, j);
            }
            set_elem(resultado, i, j, soma);
        }
    }
    return resultado;
}

tadmatriz neg(tadmatriz tadA) {
    for (int i = 0; i < tadA->linhas; i++) {
        for (int j = 0; j < tadA->colunas; j++) {
            float val = get_elem(tadA, i, j);
            set_elem(tadA, i, j, -val);
        }
    }
    return tadA;
}

tadmatriz transp(tadmatriz tadA) {
    tadmatriz transposta = cria_mat(tadA->colunas, tadA->linhas);
    for (int i = 0; i < tadA->linhas; i++) {
        for (int j = 0; j < tadA->colunas; j++) {
            float val = get_elem(tadA, i, j);
            set_elem(transposta, j, i, val);
        }
    }
    return transposta;
}

tadmatriz carrega(char *nome_arquivo) {
    FILE *file = fopen(nome_arquivo, "rt");
    if (!file) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return NULL;
    }

    int mlinhas = 0, colunas = 0;
    char linha[1024];

    while (fgets(linha, sizeof(linha), file)) {
        mlinhas++;
        char *token = strtok(linha, " \t\n");
        int colunas_temp = 0;
        while (token) {
            colunas_temp++;
            token = strtok(NULL, " \t\n");
        }
        if (mlinhas == 1) {
            colunas = colunas_temp;
        }
    }

    fclose(file);

    file = fopen(nome_arquivo, "rt");
    if (!file) {
        printf("Erro ao abrir o arquivo %s\n", nome_arquivo);
        return NULL;
    }

    tadmatriz mat = cria_mat(mlinhas, colunas);
    int tam_linha = 0;
    while (fgets(linha, sizeof(linha), file)) {
        char *token = strtok(linha, " \t\n");
        int coluna_idx = 0;
        while (token) {
            float valor = atof(token);
            set_elem(mat, tam_linha, coluna_idx, valor);
            coluna_idx++;
            token = strtok(NULL, " \t\n");
        }
        tam_linha++;
    }

    fclose(file);
    return mat;
}

tadmatriz salva(tadmatriz tadA, const char *nome_arquivo) {
    FILE *fp = fopen(nome_arquivo, "w");
    if (!fp) return NULL;

    for (int i = 0; i < tadA->linhas; i++) {
        for (int j = 0; j < tadA->colunas; j++) {
            fprintf(fp, "%8.2f", get_elem(tadA, i, j));
        }
        fprintf(fp, "\n");
    }

    fclose(fp);
    return tadA;
}
