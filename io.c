#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "io.h"

// Função para ler oq está dentro do arquivo de entrada
int ler_entrada(const char *nome_arquivo, Teste **testes) {
    FILE *arquivo = fopen(nome_arquivo, "r");
    if (!arquivo) {
        perror("Erro ao abrir arquivo de entrada");
        return 0;
    }

    int num_testes = 0;
    Teste *lista_testes = NULL;

    // lê todo o arquivo de entrar até encontrar o M == 0 e T == 0
    while (1) {
        int M, T;
        fscanf(arquivo, "%d %d", &M, &T);
        if (M == 0 && T == 0) break;

        // Faz alocação da memoria para fazer outro teste
        lista_testes = realloc(lista_testes, (num_testes + 1) * sizeof(Teste));
        lista_testes[num_testes].musica = calloc(M * 4 + 1, sizeof(char)); // Inicializa as strings
        lista_testes[num_testes].trecho = calloc(T * 4 + 1, sizeof(char));

        // for para ler as notas da m´usica
        for (int i = 0; i < M; i++) {
            char nota[4];
            fscanf(arquivo, "%s", nota);
            strcat(lista_testes[num_testes].musica, nota);
        }
        
        // for para ler as notas de um trecho
        for (int i = 0; i < T; i++) {
            char nota[4];
            fscanf(arquivo, "%s", nota);
            strcat(lista_testes[num_testes].trecho, nota);
        }

        num_testes++;
    }

    // aqui fecha o arquivo de entrar e retorna toodos os testes
    fclose(arquivo);
    *testes = lista_testes;
    return num_testes;
}

// função para esquecer o arquivo de saida (tp3.out)
void escrever_saida(const char *nome_arquivo, const char *conteudo) {
    FILE *arquivo = fopen(nome_arquivo, "w");
    if (!arquivo) {
        perror("Erro ao abrir arquivo de saida");
        return;
    }

   // aqui escreve no arquivo de saida o conteudo
    fprintf(arquivo, "%s", conteudo);
    fclose(arquivo);
}