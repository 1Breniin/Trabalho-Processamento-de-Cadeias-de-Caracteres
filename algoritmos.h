#ifndef ALGORITMOS_H
#define ALGORITMOS_H

int forca_bruta(const char *musica, const char *trecho, int *posicao);
int kmp(const char *musica, const char *trecho, int *posicao);
int boyer_moore(const char *musica, const char *trecho, int *posicao);
int shift_and(const char *musica, const char *trecho, int *posicao);

#endif