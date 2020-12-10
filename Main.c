#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "KLGenerator.h"

#define FILE_NAME "input_graph.mtx"


int main() {

    struct Graph* graph = GenerateGraphFromFile(FILE_NAME);
    if (graph == NULL) 
    {
        perror("Failed to generate graph.");
        exit(EXIT_FAILURE);
    }
    PrintGraph(graph);
    RunKLAlgorithm(graph);
    DeleteGraph(&graph);
    return 0;
}