#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


/// Ponteiro que passa a apontar para uma variável nomeada
void exemplo1(void)
{
    int x = 3;
    int *p = NULL;
    p =  &x;
    *p = *p + 1;
    printf("X = %d\n", x);
    printf("O endereço de memória da variável X é = %X\n", (int) p);
    printf("O endereço de memória da variável P é = %X\n", (int) &p);
}

/// Passagem de parâmetros por referência
void exemplo2Swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/// Impressão de array
void exemplo3Array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("Array[%2d]  = %3d\n", i, arr[i]);
}


/// Impresão de array com uso de ponteiros
void exemplo4Array(int *arr, int size)
{
    for (int i = 0; i < size; i++){
        printf("Array[%2d]  = %3d\n", i, *arr);
        arr++;
    }
}

/// Impressão de array com uso de ponteiros, outra versão
void exemplo5Array(int *arr, int size)
{
    for (int i = 0; i < size; i++)
        printf("Array[%2d]  = %3d ---- endereço --> %d\n", i, *(arr + i), (int)(arr + i));
}


/// Matrizes em C, o problema de fixar o número de colunas
/// gerando uma solução restrita a matrizes com 5 colunas
void exemplo6Matriz(int mat[][5], int linhas)
{
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < 5; j++){
            printf("%3d, ", mat[i][j]);
        }
        printf("\n");
    }
}

/// Matrizes em C, o problema da legibilidade quando trata a matriz como um array linear
void exemplo7Matriz(int *mat, int linhas, int colunas){
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++){
            printf("%3d, ", *(mat + i*colunas + j));
        }
        printf("\n");
    }
}

/// Matrizes tratadas com array de apontadores em que cada apontador aponta para um array de inteiros
void exemplo8Matriz(int **mat, int linhas, int colunas){
    for (int i =0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("%3d, ", mat[i][j]);
        }
        printf("\n");
    }
}

/// Código com BUG
/// Pegar o conteúdo de uma posição que não pode ser endereçada
void exemplo9RegiaoNaoAcessavel() {
    int *p = NULL;
    *p = 2;       /// O apontador não aponta para uma posição de memória válida
}

/// Código com BUG
/// Acessar meória não inicializada
void exemplo10PonteiroNaoInicializado() {
    int *p;
    *p = 2;       /// O apontador está apontando para lixo
}

/// Código com BUG
/// Vazamento de memória
void exemplo11VazamentoDeMemoria() {
    char *p;
    p = (char*) malloc(sizeof(char) * 100);
    strcpy(p, "IFSP - SALTO");
    printf("%s\n", p);
}

/// Código com BUG
/// Uso incorreto de variáveis. Não se pode retornar o endereço de uma variável local
/// pois as variáveis locais são destruídas assim que a função termina.
int* exemplo12AlocaRuim() {
    int array[20];
    return array; //Coisa feia
}

int main()
{
    setlocale(LC_ALL, "");
    exemplo1();

//  int a = 10;
//  int b = 20;
//  exemplo2Swap(&a, &b);
//  printf("A = %d, B = %d\n", a, b);
//
//  int arr[] = {10, 20, 30, 40, 50};
//  exemplo3Array(arr, 5);
////  exemplo4Array(arr, 5);
//
//  int arr2[] = {2, 4, 5, 6, 1, 3, 9, 0};
//  int dummy = 100;
//  exemplo5Array(arr2, 9); //Erro proposital
//
//  int mat[3][5] = { {1, 2, 3, 4, 5},
//                    {6, 7, 8, 9, 10},
//                    {11, 12, 13, 14, 15}
//                  };

//  exemplo6Matriz(mat, 3);
//  exemplo7Matriz((int*) mat, 3, 5);

//  int **mat2;
//  mat2 = (int**) malloc(sizeof(int*) * 3);
//  mat2[0] = (int *) malloc(sizeof(int) * 5);
//  mat2[1] = (int *) malloc(sizeof(int) * 5);
//  mat2[2] = (int *) malloc(sizeof(int) * 5);
//  mat2[0][0] = 1; mat2[0][1] = 2; mat2[0][2] = 3; mat2[0][3] = 4; mat2[0][4] = 5;
//  mat2[1][0] = 6; mat2[1][1] = 7; mat2[1][2] = 8; mat2[1][3] = 9; mat2[1][4] = 10;
//  mat2[2][0] = 11; mat2[2][1] = 12; mat2[2][2] = 13; mat2[2][3] = 14; mat2[2][4] = 15;
//  exemplo8Matriz(mat2, 3, 5);
//  //free(mat2); //para testar bug
//  free(mat2[0]);
//  free(mat2[1]);
//  free(mat2[2]);
//  free(mat2);

//  exemplo9RegiaoNaoAcessavel();

//  exemplo10PonteiroNaoInicializado();


//  exemplo11VazamentoDeMemoria();

//  int *arr3 = exemplo12AlocaRuim() ;
//  *arr3 = 0;
    return 0;
}
