#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "io.h"
#include "algoritmos.h"

// função para medir o tempo de execução de cada algoritmo
void medir_tempo(const char *nome_arquivo, int metodo) {
    Teste *testes;
    int num_testes = ler_entrada(nome_arquivo, &testes);

    // aq é uma verificação para saber se os dados do arquivo de entrada foram carregados corretamente
    if (num_testes == 0) {
        printf("Erro ao carregar os dados do arquivo.\n");
        return;
    }

    // variaveis para fazer a medição do tempo e contar quantas comparações
    clock_t inicio, fim;
    double tempo_gasto;
    int total_comparacoes = 0;

    // aq inicia a contagem do tempo
    inicio = clock();

    // for para executar os teste para cada entrada
    for (int i = 0; i < num_testes; i++) {
        int posicao = -1;
        int comparacoes = 0;
        
        // switch para escolher o metodo de acordo com oq o usuario escolher
        switch (metodo) {
            case 1:
                forca_bruta(testes[i].musica, testes[i].trecho, &posicao, &comparacoes);
                break;
            case 2:
                kmp(testes[i].musica, testes[i].trecho, &posicao, &comparacoes);
                break;
            case 3:
                boyer_moore(testes[i].musica, testes[i].trecho, &posicao, &comparacoes);
                break;
            case 4:
                shift_and(testes[i].musica, testes[i].trecho, &posicao, &comparacoes);
                break;
            default:
                printf("Método inválido.\n");
                return;
        }

        // armazena o total de comparações feita
        total_comparacoes += comparacoes;
    }

    // aq finaliza a contagem do tempo
    fim = clock();
    tempo_gasto = ((double)(fim - inicio)) / CLOCKS_PER_SEC;

    // print para exibir os resultados
    printf("Tempo de execução: %.6f segundos\n", tempo_gasto);
    printf("Número total de comparações: %d\n", total_comparacoes);

    // for para liberar a memoria alocada para cada teste
    for (int i = 0; i < num_testes; i++) {
        free(testes[i].musica);
        free(testes[i].trecho);
    }
    free(testes);
}