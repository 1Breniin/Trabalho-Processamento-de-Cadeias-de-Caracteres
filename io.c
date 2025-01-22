#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

int ler_entrada(const char *nome_arquivo, Teste **testes) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir arquivo de entrada");
        return 0;
    }

    int num_testes = 0;
    Teste *lista_testes = NULL;

    while (1) {
        int M, T;
        fscanf(arquivo, "%d %d", &M, &T);
        if (M == 0 && T == 0) break;

        lista_testes = realloc(lista_testes, (num_testes + 1) * sizeof(Teste));
        lista_testes[num_testes].musica = malloc((M * 3 + 1) * sizeof(char));  // 3 caracteres por nota
        lista_testes[num_testes].trecho = malloc((T * 3 + 1) * sizeof(char));

        // Lê a música
        for (int i = 0; i < M; i++) {
            char nota[4];
            fscanf(arquivo, " %s", nota);
            strcat(lista_testes[num_testes].musica, nota);
        }

        // Lê o trecho
        for (int i = 0; i < T; i++) {
            char nota[4];
            fscanf(arquivo, " %s", nota);
            strcat(lista_testes[num_testes].trecho, nota);
        }

        num_testes++;
    }

    fclose(arquivo);
    *testes = lista_testes;
    return num_testes;
}

void escrever_saida(const char *nome_arquivo, const char *conteudo) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (!arquivo) {
        perror("Erro ao abrir arquivo de saida");
        return;
    }

    fprintf(arquivo, "%s", conteudo);
    fclose(arquivo);
}