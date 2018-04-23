#include "grafo_matriz_adjacencia.h"

unsigned int **GrafoMatrizAdjacencia_alocaMatrizAdjacentes(unsigned int vertices, unsigned int valor){
    unsigned int aux_vertices, aux2_vertices;
    unsigned int **matriz_adjacentes = malloc(vertices * sizeof(unsigned int *));
    for(aux_vertices=0; aux_vertices<vertices; aux_vertices++){
        matriz_adjacentes[aux_vertices] = malloc(vertices * sizeof(unsigned int));
    }
    for(aux_vertices=0; aux_vertices<vertices; aux_vertices++){
        for(aux2_vertices=0; aux2_vertices<vertices; aux2_vertices++){
            matriz_adjacentes[aux_vertices][aux2_vertices] = valor;
        }
    }

    return matriz_adjacentes;
}

GrafoMatrizAdjacencia *GrafoMatrizAdjacencia_criar(unsigned int vertices){
    GrafoMatrizAdjacencia *grafo = (GrafoMatrizAdjacencia *) malloc(sizeof(GrafoMatrizAdjacencia));
    grafo->vertices = vertices;
    grafo->matriz_adjacentes = GrafoMatrizAdjacencia_alocaMatrizAdjacentes(vertices, 0);
    
    return grafo;
}

void GrafoMatrizAdjacencia_insereAresta(GrafoMatrizAdjacencia *grafo, unsigned int vertice1, unsigned int vertice2){
    if(vertice1 != vertice2 && grafo->matriz_adjacentes[vertice1][vertice2] == 0){
        grafo->matriz_adjacentes[vertice1][vertice2] = 1;
        grafo->matriz_adjacentes[vertice2][vertice1] = 1;
        grafo->arestas++;
    }
}

void GrafoMatrizAdjacencia_removeAresta(GrafoMatrizAdjacencia *grafo, unsigned int vertice1, unsigned int vertice2){
    if(vertice1 != vertice2 && grafo->matriz_adjacentes[vertice1][vertice2] == 1){
        grafo->matriz_adjacentes[vertice1][vertice2] = 0;
        grafo->matriz_adjacentes[vertice2][vertice1] = 0;      
        grafo->arestas--;  
    }
}

char GrafoMatrizAdjacencia_adjacentes(GrafoMatrizAdjacencia *grafo, unsigned int vertice1, unsigned int vertice2){
    char adjacentes = 1;
    if(vertice1 != vertice2 && grafo->matriz_adjacentes[vertice1][vertice2] == 0)
        adjacentes = 0;

    return adjacentes;
}

unsigned int GrafoMatrizAdjacencia_grauVertice(GrafoMatrizAdjacencia *grafo, unsigned int vertice){
    unsigned int grau = 0, cursor;
    for(cursor=0; cursor<grafo->vertices; cursor++){
        if(grafo->matriz_adjacentes[vertice][cursor] == 1)
            grau++;
    }

    return grau;
}

void GrafoMatrizAdjacencia_imprimirVerticesAdjacentes(GrafoMatrizAdjacencia *grafo, unsigned int vertice){
    unsigned int cursor;
    printf("[ ");
    for(cursor=0; cursor<grafo->vertices; cursor++){
        printf("%d ", grafo->matriz_adjacentes[vertice][cursor]);
    }
    printf("]");
}

void GrafoMatrizAdjacencia_imprimir(GrafoMatrizAdjacencia *grafo){
    unsigned int cursor;
    printf("Vertices: %d\n", grafo->vertices);
    printf("Arestas: %d\n", grafo->arestas);
    printf("Matriz Adjacencia:\n");
    for(cursor=0; cursor<grafo->vertices; cursor++){
        GrafoMatrizAdjacencia_imprimirVerticesAdjacentes(grafo, cursor);
        printf("\n");
    }
}