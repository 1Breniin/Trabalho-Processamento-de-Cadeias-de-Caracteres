#ifndef IO_H
#define IO_H

// um typedeft para armazenar a musica e o trecho para fazer a comparação
typedef struct {
    char *musica; // aq contem a musica
    char *trecho; // aq contem o trecho
} Teste;

// finção para ler os dados de entrada do arquivo
int ler_entrada(const char *nome_arquivo, Teste **testes);
// função para escrever no arquivo de saida o conteudo
void escrever_saida(const char *nome_arquivo, const char *conteudo);

#endif