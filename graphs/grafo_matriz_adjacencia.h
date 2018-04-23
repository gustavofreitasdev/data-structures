#include <stdlib.h>
#include <stdio.h>

typedef struct grafo_tipo{
    unsigned int vertices;
    unsigned int arestas;
    unsigned int **matriz_adjacentes;
} GrafoMatrizAdjacencia;

unsigned int **GrafoMatrizAdjacencia_alocaMatrizAdjacentes(unsigned int vertices, unsigned int valor);

GrafoMatrizAdjacencia *GrafoMatrizAdjacencia_criar(unsigned int vertices);

void GrafoMatrizAdjacencia_insereAresta(GrafoMatrizAdjacencia *grafo, unsigned int vertice1, unsigned int vertice2);

void GrafoMatrizAdjacencia_removeAresta(GrafoMatrizAdjacencia *grafo, unsigned int vertice1, unsigned int vertice2);

char GrafoMatrizAdjacencia_adjacentes(GrafoMatrizAdjacencia *grafo, unsigned int vertice1, unsigned int vertice2);

unsigned int GrafoMatrizAdjacencia_grauVertice(GrafoMatrizAdjacencia *grafo, unsigned int vertice);

void GrafoMatrizAdjacencia_imprimirVerticesAdjacentes(GrafoMatrizAdjacencia *grafo, unsigned int vertice);

void GrafoMatrizAdjacencia_imprimir(GrafoMatrizAdjacencia *grafo);

