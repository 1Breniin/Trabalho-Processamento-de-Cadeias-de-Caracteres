#ifndef IO_H
#define IO_H

typedef struct {
    char *musica;
    char *trecho;
} Teste;

int ler_entrada(const char *nome_arquivo, Teste **testes);
void escrever_saida(const char *nome_arquivo, const char *conteudo);

#endif