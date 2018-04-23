#include <stdlib.h>

typedef struct grafo_tipo{
    unsigned int vertices;
    unsigned int arestas;
    unsigned int **matriz_adjacentes;
} GrafoMatrizAdjacencia;

unsigned int **GrafoMatrizAdjacencia_alocaMatrizAdjacentes(unsigned int vertices, unsigned int arestas, unsigned int valor);

GrafoMatrizAdjacencia *GrafoMatrizAdjacencia_criar(unsigned int vertices);

void GrafoMatrizAdjacencia_insereAresta(GrafoMatrizAdjacencia *grafo, unsigned int vertice, unsigned int aresta);

void GrafoMatrizAdjacencia_removeAresta(GrafoMatrizAdjacencia *grafo, unsigned int vertice_origem, unsigned int vertice_destino);

char GrafoMatrizAdjacencia_adjacentes(GrafoMatrizAdjacencia *grafo, unsigned int vertice_origem, unsigned int vertice_destino);

unsigned int GrafoMatrizAdjacencia_grauVertice(GrafoMatrizAdjacencia *grafo, unsigned int vertice);

void GrafoMatrizAdjacencia_imprimirVerticesAdjacentes(GrafoMatrizAdjacencia *grafo, unsigned int vertice);

void GrafoMatrizAdjacencia_imprimir(GrafoMatrizAdjacencia *grafo);

