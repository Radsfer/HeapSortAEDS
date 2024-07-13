#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Função para trocar dois elementos
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função para reorganizar a sub-árvore com a raiz no índice i
void heapify(int *arr, int n, int i, int min_heap) {
    int extremo = i;       // Inicializa o extremo como raiz
    int esq = 2 * i + 1; // filho da esquerda
    int dir = 2 * i + 2; // filho da direita

    if (min_heap) {
        if (esq < n && arr[esq] < arr[extremo])
            extremo = esq;
        if (dir < n && arr[dir] < arr[extremo])
            extremo = dir;
    } else {
        if (esq < n && arr[esq] > arr[extremo])
            extremo = esq;
        if (dir < n && arr[dir] > arr[extremo])
            extremo = dir;
    }

    // Se o extremo não é a raiz
    if (extremo != i) {
        swap(&arr[i], &arr[extremo]); // troca
        heapify(arr, n, extremo, min_heap);
    }
}

// Função principal para realizar o Heap Sort
void heapSort(int *arr, int n, int min_heap) {
    // Construir o heap (reorganizar o array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, min_heap);

    // Extrair elementos do heap um a um
    for (int i = n - 1; i >= 0; i--) {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0, min_heap);
    }
}

// Função para imprimir o array
void printArray(int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Função para ler números do arquivo
void read_numbers_from_file(const char *filename, int *arr, int n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(file, "%d", &arr[i]) != 1) {
            perror("Erro ao ler o arquivo");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}

// Função para salvar dados em arquivo
void salvarDadosEmArquivo(const char *filename, int tamanho, double tempo, const char *tipo) {
    FILE *file = fopen(filename, "a");
    if (file == NULL) {
        perror("Erro ao abrir o arquivo para escrita");
        exit(EXIT_FAILURE);
    }

    fprintf(file, "Tamanho do vetor: %d, Tempo médio gasto (%s): %.6f segundos\n", tamanho, tipo, tempo);
    fclose(file);
}

// Função para gerar um array em ordem crescente
void generate_sorted_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
}

// Função para gerar um array em ordem decrescente
void generate_reverse_sorted_array(int *arr, int n) {
    for (int i = 0; i < n; i++) {
        arr[i] = n - i;
    }
}

// Função principal
int main() {
    int n[] = {10, 100, 1000, 10000, 100000, 200000, 400000, 800000, 1000000};
    int tamanhoN = sizeof(n) / sizeof(n[0]);

    for (int i = 0; i < tamanhoN; i++) {
        int* array = (int*)malloc(n[i] * sizeof(int));
        if (array == NULL) {
            perror("Erro ao alocar memória");
            exit(EXIT_FAILURE);
        }

        // Teste com array aleatório do arquivo
        read_numbers_from_file("input.txt", array, n[i]);
        clock_t inicio, fim;
        double tempoGasto = 0.0;
        int iteracoes = 10;

        for (int k = 0; k < iteracoes; k++) {
            int* copia = (int*)malloc(n[i] * sizeof(int));
            if (copia == NULL) {
                perror("Erro ao alocar memória");
                exit(EXIT_FAILURE);
            }
            memcpy(copia, array, n[i] * sizeof(int));

            inicio = clock();
            heapSort(copia, n[i], 0); // max heap para ordenação crescente
            fim = clock();
            tempoGasto += ((double)(fim - inicio)) / CLOCKS_PER_SEC;

            free(copia);
        }

        tempoGasto /= iteracoes;

        printf("Tamanho do vetor: %d\n", n[i]);
        printf("Tempo médio gasto (aleatório): %.6f segundos\n", tempoGasto);
        salvarDadosEmArquivo("TempoMedio.txt", n[i], tempoGasto, "aleatório");

        // Teste com array em ordem crescente
        generate_sorted_array(array, n[i]);
        tempoGasto = 0.0;

        for (int k = 0; k < iteracoes; k++) {
            int* copia = (int*)malloc(n[i] * sizeof(int));
            if (copia == NULL) {
                perror("Erro ao alocar memória");
                exit(EXIT_FAILURE);
            }
            memcpy(copia, array, n[i] * sizeof(int));

            inicio = clock();
            heapSort(copia, n[i], 0); // max heap para ordenação crescente
            fim = clock();
            tempoGasto += ((double)(fim - inicio)) / CLOCKS_PER_SEC;

            free(copia);
        }

        tempoGasto /= iteracoes;

        printf("Tempo médio gasto (crescente): %.6f segundos\n", tempoGasto);
        salvarDadosEmArquivo("TempoMedio.txt", n[i], tempoGasto, "crescente");

        // Teste com array em ordem decrescente
        generate_reverse_sorted_array(array, n[i]);
        tempoGasto = 0.0;

        for (int k = 0; k < iteracoes; k++) {
            int* copia = (int*)malloc(n[i] * sizeof(int));
            if (copia == NULL) {
                perror("Erro ao alocar memória");
                exit(EXIT_FAILURE);
            }
            memcpy(copia, array, n[i] * sizeof(int));

            inicio = clock();
            heapSort(copia, n[i], 0); // max heap para ordenação crescente
            fim = clock();
            tempoGasto += ((double)(fim - inicio)) / CLOCKS_PER_SEC;

            free(copia);
        }

        tempoGasto /= iteracoes;

        printf("Tempo médio gasto (decrescente): %.6f segundos\n", tempoGasto);
        salvarDadosEmArquivo("TempoMedio.txt", n[i], tempoGasto, "decrescente");

        free(array);
    }

    return 0;
}

