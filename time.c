#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "io.h"
#include "algoritmos.h"

void medir_tempo(const char *nome_arquivo, int metodo) {
    Teste *testes;
    int num_testes = ler_entrada(nome_arquivo, &testes);

    if (num_testes == 0) {
        printf("Erro ao carregar os dados do arquivo.\n");
        return;
    }

    clock_t inicio, fim;
    double tempo_gasto;

    inicio = clock();

    for (int i = 0; i < num_testes; i++) {
        int posicao = -1;
        switch (metodo) {
            case 1:
                forca_bruta(testes[i].musica, testes[i].trecho, &posicao);
                break;
            case 2:
                kmp(testes[i].musica, testes[i].trecho, &posicao);
                break;
            case 3:
                boyer_moore(testes[i].musica, testes[i].trecho, &posicao);
                break;
            case 4:
                shift_and(testes[i].musica, testes[i].trecho, &posicao);
                break;
            default:
                printf("Método inválido.\n");
                return;
        }
    }

    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.6f segundos\n", tempo_gasto);

    for (int i = 0; i < num_testes; i++) {
        free(testes[i].musica);
        free(testes[i].trecho);
    }
    free(testes);
}