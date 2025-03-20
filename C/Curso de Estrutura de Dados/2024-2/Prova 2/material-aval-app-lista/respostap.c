#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tadlista.h"

typedef struct {
    char id_projeto[128];
    char nome_projeto[128];
    char descricao_projeto[128];
} t_projeto;

typedef struct {
    char id_membro[128];
    char nome_membro[128];
} t_membro;

typedef struct {
    char r_membro[128];
    char r_projeto[128];
} t_relacao;

Lista load_projetos(char *fileName) {
    Lista lst_projetos = criaLista();
    FILE *file = fopen(fileName, "rt");
    
    t_projeto *projeto;

    while (!feof(file)) {
        projeto = (t_projeto *)malloc(sizeof(t_projeto));

        if (fscanf(file, "%s, %[^,], %[^\n]\n", projeto->id_projeto, projeto->nome_projeto, projeto->descricao_projeto) == 3) {
            lst_projetos = appendLista(lst_projetos, projeto);
        }
    }

    fclose(file);
    return lst_projetos;
}

Lista load_membros(char *fileName){

    Lista lst_membros = criaLista();
    FILE *file = fopen(fileName, "rt");
    
    t_membro *membro;
    
    while (!feof(file)) {
        membro = (t_membro *)malloc(sizeof(t_membro));

        if (fscanf(file, "%s, %[^\n]\n", membro->id_membro, membro->nome_membro) == 2) {
            lst_membros = appendLista(lst_membros, membro);
        }
    }

    fclose(file);
    return lst_membros;
}

Lista load_relacoes(char *fileName){
    Lista lst_relacoes = criaLista();
    FILE *file = fopen(fileName, "rt");
    
    t_relacao *relacao;

    while (!feof(file)) {
        relacao = (t_relacao *)malloc(sizeof(t_relacao));

        if (fscanf(file, "%[^,], %[^\n]\n", relacao->r_membro, relacao->r_projeto) == 2) {
            lst_relacoes = appendLista(lst_relacoes, relacao);
        }
    }

    fclose(file);
    return lst_relacoes;
}

Lista membros_projeto(char *id_proj, Lista lst_relacoes, Lista lst_membros) {
    Lista lst_membros_projeto = criaLista();
    int encontrou = 0;

    printf("\nMembros do Projeto %s:\n", id_proj);

    for (int i = 0; i < lenLista(lst_relacoes); i++) {
        t_relacao *relacao = (t_relacao *)dadoLista(lst_relacoes, i);

        if (strcmp(relacao->r_projeto, id_proj) == 0) {
            for (int j = 0; j < lenLista(lst_membros); j++) {
                t_membro *membro = (t_membro *)dadoLista(lst_membros, j);
                if (strcmp(membro->id_membro, relacao->r_membro) == 0) {
                    lst_membros_projeto = appendLista(lst_membros_projeto, membro);
                    printf("%s\n", membro->nome_membro);
                    encontrou = 1;
                }
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum membro encontrado para este projeto.\n");
    }

    return lst_membros_projeto;
}

Lista projetos_membro(char *id_mem, Lista lst_relacoes, Lista lst_projetos) {
    Lista lst_projetos_membro = criaLista();
    int encontrou = 0;

    printf("\nProjetos do Membro %s:\n", id_mem);

    for (int i = 0; i < lenLista(lst_relacoes); i++) {
        t_relacao *relacao = (t_relacao *)dadoLista(lst_relacoes, i);

        if (strcmp(relacao->r_membro, id_mem) == 0) {
            for (int j = 0; j < lenLista(lst_projetos); j++) {
                t_projeto *projeto = (t_projeto *)dadoLista(lst_projetos, j);
                if (strcmp(projeto->id_projeto, relacao->r_projeto) == 0) {
                    lst_projetos_membro = appendLista(lst_projetos_membro, projeto);
                    printf("%s - %s\n", projeto->nome_projeto, projeto->descricao_projeto);
                    encontrou = 1;
                }
            }
        }
    }

    if (!encontrou) {
        printf("Nenhum projeto encontrado para este membro.\n");
    }

    return lst_projetos_membro;
}

int main(){
    char bdprojetos[128] = "bdprojetos";
    Lista lst_projetos = load_projetos(bdprojetos);

    char bdmembros[128] = "bdmembros";
    Lista lst_membros = load_membros(bdmembros);

    char bdrelacoes[128] = "bdrelacoes";
    Lista lst_relacoes = load_relacoes(bdrelacoes);

    int resposta = 0;
    puts("\nMENU APP LISTA\n================================\n1. Membros de 1 Projeto\n2. Projetos de 1 Membro\n3. Sair\nEscolha 1 opcao:\n================================\n");
    scanf("%d", &resposta);

    while (resposta != 3) {
        if (resposta < 1 || resposta > 3) {
            puts("Resposta Invalida");
        }

        if (resposta == 1) {
            char id_proj[128];
            printf("Digite o ID do Projeto: ");
            scanf("%s", id_proj);
            
            membros_projeto(id_proj, lst_relacoes, lst_membros);

        } else if (resposta == 2) {

            char id_mem[128];
            printf("Digite o ID do Membro: ");
            scanf("%s", id_mem);
            
            projetos_membro(id_mem, lst_relacoes, lst_projetos);
        }
        
        puts("\nMENU APP LISTA\n================================\n1. Membros de 1 Projeto\n2. Projetos de 1 Membro\n3. Sair\nEscolha 1 opcao:\n================================\n");
        scanf("%d", &resposta);
    }

    return 0;
}
