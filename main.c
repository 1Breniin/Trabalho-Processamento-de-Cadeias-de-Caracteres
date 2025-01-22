#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "algoritmos.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"
#include "algoritmos.h"

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Uso: %s <arquivo_de_entrada> <metodo>\n", argv[0]);
        return 1;
    }

    char *nome_arquivo = argv[1];
    int metodo = atoi(argv[2]);

    // Carrega os casos de teste
    Teste *testes;
    int num_testes = ler_entrada(nome_arquivo, &testes);

    if (num_testes == 0) {
        printf("Erro ao carregar os dados do arquivo.\n");
        return 1;
    }

    // Buffer para armazenar os resultados
    char resultados[1024] = "";

    // Percorre os testes e acumula as respostas
    for (int i = 0; i < num_testes; i++) {
        int posicao = -1;
        int plagiado = 0;

        // Realiza a busca com o método selecionado
        switch (metodo) {
            case 1:
                plagiado = forca_bruta(testes[i].musica, testes[i].trecho, &posicao);
                break;
            case 2:
                plagiado = kmp(testes[i].musica, testes[i].trecho, &posicao);
                break;
            case 3:
                plagiado = boyer_moore(testes[i].musica, testes[i].trecho, &posicao);
                break;
            case 4:
                plagiado = shift_and(testes[i].musica, testes[i].trecho, &posicao);
                break;
            default:
                printf("Método inválido.\n");
                return 1;
        }

        // Formata o resultado
        char linha_resultado[64];
        if (plagiado) {
            snprintf(linha_resultado, sizeof(linha_resultado), "S %d\n", posicao);
        } else {
            snprintf(linha_resultado, sizeof(linha_resultado), "N\n");
        }

        // Adiciona o resultado no buffer de forma correta
        strcat(resultados, linha_resultado);
    }

    // Salva os resultados no arquivo de saída
    escrever_saida("tp3.out", resultados);

    // Libera memória alocada
    for (int i = 0; i < num_testes; i++) {
        free(testes[i].musica);
        free(testes[i].trecho);
    }
    free(testes);

    return 0;
}