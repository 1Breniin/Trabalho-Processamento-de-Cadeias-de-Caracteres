# Trabalho Prático 3: Processamento de Cadeias de Caracteres

Este projeto tem como objetivo implementar e comparar diferentes métodos de casamento de padrões de cadeias de caracteres para identificar plágio de melodias em diferentes tons.

## Estrutura do Projeto

O código está dividido em arquivos para facilitar a manutenção e organização:

- **`main.c`**: Responsável por controlar o fluxo principal do programa.
- **`io.h` e `io.c`**: Contêm funções para leitura de entrada e escrita de saída.
- **`algoritmos.h` e `algoritmos.c`**: Implementação dos métodos de casamento de padrões:
  - Força Bruta
  - KMP (Knuth-Morris-Pratt)
  - Boyer-Moore
  - Shift-And
- **`Makefile`**: Arquivo de configuração para compilação automática.

## Compilação

Para compilar o programa, utilize o seguinte comando no terminal:

```bash
make
```

O executável será gerado com o nome `tp3`.

## Execução

Para executar o programa, utilize o comando:

```bash
./tp3 <arquivo_de_entrada> <metodo>
```

Onde:
- `<arquivo_de_entrada>` é o caminho para o arquivo de entrada contendo os casos de teste.
- `<metodo>` é o número correspondente ao método de casamento de padrões:
  - 1: Força Bruta
  - 2: KMP
  - 3: Boyer-Moore
  - 4: Shift-And

### Exemplo de Execução

```bash
./tp3 entrada.txt 1
```

## Entrada e Saída

### Formato do Arquivo de Entrada

O arquivo de entrada deve conter:
- Na primeira linha de cada caso de teste: dois inteiros `M` e `T`, representando o número de notas da música e do trecho suspeito.
- Nas duas linhas seguintes:
  - `M` notas representando a música.
  - `T` notas representando o trecho suspeito.
- Uma linha contendo `0 0` para indicar o final dos casos de teste.

#### Exemplo de Entrada

```txt
16 4
D G A B C D G G G C D E F# G C C
G G C D
12 2
C C# D D# E F F# G G# A A# B
C D
0 0
```

### Formato do Arquivo de Saída

- Para cada caso de teste:
  - Imprima `S <posicao>` caso o trecho tenha sido encontrado, indicando a posição inicial na música.
  - Imprima `N` caso contrário.

#### Exemplo de Saída

```txt
S 7
N
```

## Estruturas e Funções Implementadas

### Algoritmos de Casamento de Padrões

1. **Força Bruta**:
   - Percorre todas as possíveis posições na música para verificar se o trecho está presente.

2. **KMP (Knuth-Morris-Pratt)**:
   - Utiliza um array de prefixos para evitar comparações redundantes.

3. **Boyer-Moore**:
   - Faz saltos com base na tabela de deslocamento das letras, otimizando buscas em textos grandes.

4. **Shift-And**:
   - Realiza buscas baseadas em operações bitwise para padrões pequenos.

### Métricas de Desempenho

O programa registra:
- Número de comparações realizadas.
- Tempo de execução de cada método (utilizando `gettimeofday`).

## Limpeza

Para remover os arquivos compilados, utilize:

```bash
make clean
```

## Requisitos

- Compilador GCC
- Sistema operacional Linux

## Observações

- O programa foi testado e validado para uso nos laboratórios do DCOMP.
- Certifique-se de seguir o formato especificado para os arquivos de entrada e saída.

