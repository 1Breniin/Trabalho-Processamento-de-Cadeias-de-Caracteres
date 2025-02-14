#include <string.h>
#include <stdlib.h>
#include "algoritmos.h"

#include <stdio.h>
#include <string.h>

// implementação do algortimo de Força bruta
int forca_bruta(const char *musica, const char *trecho, int *posicao, int *comparacoes) {
    int n = strlen(musica); // Tamanho da música
    int m = strlen(trecho); // Tamanho do trecho
    *comparacoes = 0;

    // Percorre todas as possíveis posições de início na música
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        // Compara o trecho com a parte da música
        while (j < m && musica[i + j] == trecho[j]) {
            (*comparacoes)++;  // Conta cada comparação feita
            j++;
        }
        // Se o trecho for encontrado
        if (j == m) {
            *posicao = i; // Armazena a posição
            printf("[Força Bruta] Trecho encontrado na posição: %d\n", i);
            return 1; // Trecho encontrado
        }
    }
    return 0;
}

// implementação do algortimo Kmp
int kmp(const char *musica, const char *trecho, int *posicao, int *comparacoes) {
    int n = strlen(musica);
    int m = strlen(trecho);
    int lps[m]; // Longest Prefix Suffix array
    *comparacoes = 0;
    
    // Pré-processamento da tabela LPS
    int j = 0;
    lps[0] = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && trecho[i] != trecho[j]) {
            j = lps[j - 1];
            (*comparacoes)++;
        }
        if (trecho[i] == trecho[j]) {
            j++;
        }
        lps[i] = j;
    }
    
    // Algoritmo KMP
    j = 0;
    for (int i = 0; i < n; i++) {
        (*comparacoes)++;
        while (j > 0 && musica[i] != trecho[j]) {
            j = lps[j - 1];
            (*comparacoes)++;
        }
        if (musica[i] == trecho[j]) {
            j++;
        }
        if (j == m) {
            *posicao = i - m + 1;
            printf("[KMP] Trecho encontrado na posição: %d\n", *posicao);
            return 1; // Padrão encontrado
        }
    }
    return 0; //Padrão não encontrado
}

// implementação do algortimo de Boyer-moore
int boyer_moore(const char *musica, const char *trecho, int *posicao, int *comparacoes) {
    int n = strlen(musica); // Tamanho do texto
    int m = strlen(trecho); //Tamanho do padrão
    *comparacoes = 0;

    if (m > n) {
        return 0; // Padrão maior que o texto, impossível casar
    }
    
    // Construção da tabela de bad-character
    int bad_char[256];
    for (int i = 0; i < 256; i++) {
        bad_char[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        bad_char[(unsigned char)trecho[i]] = i;
    }
    
    // Busca usando o Boyer-Moore
    int shift = 0; // Deslocamento no texto
    while (shift <= (n - m)) {
        int j = m - 1;

        // Encontra a correspondência da direita para a esquerda
        while (j >= 0 && trecho[j] == musica[shift + j]) {
            (*comparacoes)++;
            j--;
        }
        if (j < 0) {
            *posicao = shift; // Match encontrado
            printf("[Boyer-Moore] Trecho encontrado na posição: %d\n", shift);
            return 1;
        } else {
            // Desloca de acordo com a tabela de bad-character
            shift += (j - bad_char[(unsigned char)musica[shift + j]] > 1) ? j - bad_char[(unsigned char)musica[shift + j]] : 1;
        }
    }
    return 0;
}

// implementação do algortimo Shift-and
int shift_and(const char *musica, const char *trecho, int *posicao, int *comparacoes) {
    int n = strlen(musica);
    int m = strlen(trecho);
    *comparacoes = 0;

    if (m > 64) {
        fprintf(stderr, "Erro: O Shift-And suporta padrões de até 64 caracteres.\n");
        return 0;
    }

    unsigned long long int msk[256] = {0}; // Máscaras para todos os caracteres
    for (int i = 0; i < m; i++) {
        msk[(unsigned char)trecho[i]] |= (1ULL << i);
    }

    unsigned long long int S = 0; // Estado atual
    for (int i = 0; i < n; i++) {
        S = ((S << 1) | 1) & msk[(unsigned char)musica[i]];
        (*comparacoes)++;
        if (S & (1ULL << (m - 1))) {
            *posicao = i - m + 1;
            printf("[Shift-And] Trecho encontrado na posição: %d\n", *posicao);
            return 1;
        }
    }
    return 0;
}