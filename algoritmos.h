#ifndef ALGORITMOS_H
#define ALGORITMOS_H

// Função para implementar o Força bruta
int forca_bruta(const char *musica, const char *trecho, int *posicao, int *comparacoes);
// Função para implementar o Kmp
int kmp(const char *musica, const char *trecho, int *posicao, int *comparacoes);
// Função para implementar o Boyer-moore
int boyer_moore(const char *musica, const char *trecho, int *posicao, int *comparacoes);
// Função para implementar o Sihft-and
int shift_and(const char *musica, const char *trecho, int *posicao, int *comparacoes);

#endif