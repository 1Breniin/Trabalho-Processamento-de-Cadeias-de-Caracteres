#include <string.h>
#include <stdlib.h>
#include "algoritmos.h"

#include <stdio.h>
#include <string.h>

int forca_bruta(const char *musica, const char *trecho, int *posicao) {
    int n = strlen(musica);  // Tamanho da música
    int m = strlen(trecho);  // Tamanho do trecho

    // Percorre todas as possíveis posições de início na música
    for (int i = 0; i <= n - m; i++) {
        int j = 0;
        // Compara o trecho com a parte da música
        while (j < m && musica[i + j] == trecho[j]) {
            j++;
        }
        // Se o trecho for encontrado
        if (j == m) {
            *posicao = i;  // Armazena a posição inicial
            printf("Encontrado na posição %d\n", i);  // Debug
            return 1;  // Trecho encontrado
        }
    }

    return 0;  // Trecho não encontrado
}

int kmp(const char *musica, const char *trecho, int *posicao) {
    int n = strlen(musica);
    int m = strlen(trecho);
    int lps[m]; // Longest Prefix Suffix array

    // Pré-processamento da tabela LPS
    int j = 0;
    lps[0] = 0;
    for (int i = 1; i < m; i++) {
        while (j > 0 && trecho[i] != trecho[j]) {
            j = lps[j - 1];
        }
        if (trecho[i] == trecho[j]) {
            j++;
        }
        lps[i] = j;
    }

    // Algoritmo KMP
    j = 0;
    for (int i = 0; i < n; i++) {
        while (j > 0 && musica[i] != trecho[j]) {
            j = lps[j - 1];
        }
        if (musica[i] == trecho[j]) {
            j++;
        }
        if (j == m) {
            *posicao = i - m + 1; // Ajuste da posição
            return 1; // Padrão encontrado
        }
    }
    return 0; // Padrão não encontrado
}

int boyer_moore(const char *musica, const char *trecho, int *posicao) {
    int n = strlen(musica);
    int m = strlen(trecho);

    // Tabela de bad character
    int bad_char[256]; // Supondo ASCII
    for (int i = 0; i < 256; i++) {
        bad_char[i] = -1;
    }
    for (int i = 0; i < m; i++) {
        bad_char[(unsigned char)trecho[i]] = i;
    }

    int i = 0;
    while (i <= n - m) {
        int j = m - 1;
        while (j >= 0 && musica[i + j] == trecho[j]) {
            j--;
        }
        if (j < 0) {
            *posicao = i; // A posição do início do trecho
            printf("Encontrado na posição %d\n", i);  // Debug
            return 1;
        } else {
            i += (j - bad_char[(unsigned char)musica[i + j]]);
        }
    }
    return 0;
}

int shift_and(const char *musica, const char *trecho, int *posicao) {
    int n = strlen(musica);
    int m = strlen(trecho);

    unsigned long long int mascara = 1; // Máscara para a primeira posição
    unsigned long long int msk[m]; // Vetor de máscaras

    // Construção das máscaras para o padrão
    for (int i = 0; i < m; i++) {
        msk[i] = 0;
        for (int j = 0; j < n; j++) {
            if (trecho[i] == musica[j]) {
                msk[i] |= (1 << j);
            }
        }
    }

    unsigned long long int S = 0;
    for (int i = 0; i < n; i++) {
        S |= (1 << i); // Atualiza o shift
        for (int j = 0; j < m; j++) {
            if ((S & msk[j]) == msk[j]) {
                *posicao = i - m + 1; // Ajusta a posição correta
                printf("Encontrado na posição %d\n", i);  // Debug
                printf("Encontrado na posição %d\n", i);  // Debug
                return 1;
            }
        }
    }
    return 0;
}