#ifndef ALGORITMOS_H
#define ALGORITMOS_H

int forca_bruta(const char *musica, const char *trecho, int *posicao, int *comparacoes);
int kmp(const char *musica, const char *trecho, int *posicao, int *comparacoes);
int boyer_moore(const char *musica, const char *trecho, int *posicao, int *comparacoes);
int shift_and(const char *musica, const char *trecho, int *posicao, int *comparacoes);

#endif