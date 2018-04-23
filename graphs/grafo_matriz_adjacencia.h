#include <stdlib.h>
#include <stdio.h>

/* Tipo GrafoMatrizAdjacencia, são armazenadas algumas informações.
   Quantidade de vertices.
   Quantidade de arestas.
   Matriz de adjacencia contendo apenas 0, 1. Onde 1 representa uma ligação (aresta).
*/
typedef struct grafo_tipo{
    unsigned int vertices;
    unsigned int arestas;
    unsigned int **matriz_adjacentes;
} GrafoMatrizAdjacencia;

// Aloca a matriz de adjacencia, cria uma matriz de tamanho 'vertices x vertices', com todos os valores de arestas igual a 'valor'
unsigned int **GrafoMatrizAdjacencia_alocaMatrizAdjacentes(unsigned int vertices, unsigned int valor);
// Cria um grafo baseado no número de vertices
GrafoMatrizAdjacencia *GrafoMatrizAdjacencia_criar(unsigned int vertices);
// Insere uma aresta no grafo, dado dois vertices
void GrafoMatrizAdjacencia_insereAresta(GrafoMatrizAdjacencia *grafo, unsigned int vertice1, unsigned int vertice2);
// Remove uma aresta no grafo, dado dois vertices
void GrafoMatrizAdjacencia_removeAresta(GrafoMatrizAdjacencia *grafo, unsigned int vertice1, unsigned int vertice2);
// Verifica se dois vertices são adjacentes
char GrafoMatrizAdjacencia_adjacentes(GrafoMatrizAdjacencia *grafo, unsigned int vertice1, unsigned int vertice2);
// Calcula o grau de um vertice
unsigned int GrafoMatrizAdjacencia_grauVertice(GrafoMatrizAdjacencia *grafo, unsigned int vertice);
// Imprime todos os vertices adjacentes ao vertice passado
void GrafoMatrizAdjacencia_imprimirVerticesAdjacentes(GrafoMatrizAdjacencia *grafo, unsigned int vertice);
// Imprime todo o grafo
void GrafoMatrizAdjacencia_imprimir(GrafoMatrizAdjacencia *grafo);