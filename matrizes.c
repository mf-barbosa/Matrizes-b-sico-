#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QTD_LINHAS 100
#define QTD_COLUNAS 100

void lerMatriz(int mat[][QTD_COLUNAS], int lin, int col);
void preencherMatrizAleatoria(int mat[][QTD_COLUNAS], int lin, int col);
void imprimirMatriz(int mat[][QTD_COLUNAS], int lin, int col);
int lerDentroIntervalo(int min, int max);
int contarImpares(int mat[][QTD_COLUNAS], int lin, int col);
int encontrarElemento(int mat[][QTD_COLUNAS], int lin, int col, int elem);
int somatorioMatriz(int mat[][QTD_COLUNAS], int lin, int col);
double mediaMatriz(int mat[][QTD_COLUNAS], int lin, int col);
void mediaPorLinha(int mat[][QTD_COLUNAS], int lin, int col);

int main() {
    int qtdLinhas, qtdColunas;
    int matriz[QTD_LINHAS][QTD_COLUNAS];

    srand(time(0)); 

    printf("Digite a quantidade de linhas (1-%d): ", QTD_LINHAS);
    qtdLinhas = lerDentroIntervalo(1, QTD_LINHAS);
    printf("Digite a quantidade de colunas (1-%d): ", QTD_COLUNAS);
    qtdColunas = lerDentroIntervalo(1, QTD_COLUNAS);

    preencherMatrizAleatoria(matriz, qtdLinhas, qtdColunas);
    printf("\nMatriz Gerada:\n");
    imprimirMatriz(matriz, qtdLinhas, qtdColunas);

    int qtdImpares = contarImpares(matriz, qtdLinhas, qtdColunas);
    printf("\nQuantidade de numeros impares na matriz: %d\n", qtdImpares);

    int elemento;
    printf("\nDigite o elemento que deseja procurar na matriz: ");
    scanf("%d", &elemento);
    if (!encontrarElemento(matriz, qtdLinhas, qtdColunas, elemento)) {
        printf("Elemento %d nao encontrado na matriz.\n", elemento);
    }

    int soma = somatorioMatriz(matriz, qtdLinhas, qtdColunas);
    printf("\nSomatorio de todos os elementos da matriz: %d\n", soma);

    double media = mediaMatriz(matriz, qtdLinhas, qtdColunas);
    printf("Media de todos os elementos da matriz: %.2lf\n", media);

    printf("\nMedia de cada linha da matriz:\n");
    mediaPorLinha(matriz, qtdLinhas, qtdColunas);

    return 0;
}

void lerMatriz(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("Digite mat[%d][%d]: ", i, j);
            scanf("%d", &mat[i][j]);
        }
    }
}

void preencherMatrizAleatoria(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            mat[i][j] = rand() % 100 + 1;
        }
    }
}

void imprimirMatriz(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}

int lerDentroIntervalo(int min, int max) {
    int valor;
    scanf("%d", &valor);
    while (valor < min || valor > max) {
        printf("Valor invalido! Digite valor entre %d e %d: ", min, max);
        scanf("%d", &valor);
    }
    return valor;
}

int contarImpares(int mat[][QTD_COLUNAS], int lin, int col) {
    int count = 0;
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            if (mat[i][j] % 2 != 0) {
                count++;
            }
        }
    }
    return count;
}

int encontrarElemento(int mat[][QTD_COLUNAS], int lin, int col, int elem) {
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            if (mat[i][j] == elem) {
                printf("Elemento %d encontrado na linha %d, coluna %d.\n", elem, i, j);
                return 1; 
            }
        }
    }
    return 0; 
}

int somatorioMatriz(int mat[][QTD_COLUNAS], int lin, int col) {
    int soma = 0;
    for (int i = 0; i < lin; ++i) {
        for (int j = 0; j < col; ++j) {
            soma += mat[i][j];
        }
    }
    return soma;
}

double mediaMatriz(int mat[][QTD_COLUNAS], int lin, int col) {
    int soma = somatorioMatriz(mat, lin, col);
    return (double)soma / (lin * col);
}

void mediaPorLinha(int mat[][QTD_COLUNAS], int lin, int col) {
    for (int i = 0; i < lin; ++i) {
        int soma = 0;
        for (int j = 0; j < col; ++j) {
            soma += mat[i][j];
        }
        printf("Media da linha %d: %.2lf\n", i, (double)soma / col);
    }
}