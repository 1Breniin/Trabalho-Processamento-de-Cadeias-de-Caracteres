#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "algoritmos.h"
#include "time.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <arquivo_de_entrada> <metodo>\n", argv[0]);
        return 1;
    }

   char *nome_arquivo = argv[1];
    int metodo = atoi(argv[2]);

    Teste *testes;
    int num_testes = ler_entrada(nome_arquivo, &testes);
    if (num_testes == 0) {
        printf("Erro ao carregar os dados do arquivo.\n");
        return 1;
    }

    FILE *saida = fopen("tp3.out", "w");
    if (!saida) {
        perror("Erro ao abrir arquivo de saída");
        return 1;
    }

    medir_tempo(nome_arquivo, metodo);

    for (int i = 0; i < num_testes; i++) {
        int posicao = -1;
        int plagiado = 0;
        int comparacoes = 0;

        switch (metodo) {
            case 1: plagiado = forca_bruta(testes[i].musica, testes[i].trecho, &posicao, &comparacoes); break;
            case 2: plagiado = kmp(testes[i].musica, testes[i].trecho, &posicao, &comparacoes); break;
            case 3: plagiado = boyer_moore(testes[i].musica, testes[i].trecho, &posicao, &comparacoes); break;
            case 4: plagiado = shift_and(testes[i].musica, testes[i].trecho, &posicao, &comparacoes); break;
            default: fprintf(stderr, "Método inválido.\n"); return 1;
        }

        if (plagiado) {
            fprintf(saida, "S %d\n", posicao);
        } else {
            fprintf(saida, "N\n");
        }

        printf("Teste %d: Comparações = %d\n", i + 1, comparacoes);
        
    }

    fclose(saida);

    for (int i = 0; i < num_testes; i++) {
        free(testes[i].musica);
        free(testes[i].trecho);
    }
    free(testes);

    return 0;
}