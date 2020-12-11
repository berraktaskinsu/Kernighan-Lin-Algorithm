#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "KLGenerator.h"

#define FILE1_NAME "input_graph.mtx"
#define FILE2_NAME "Erdos02.mtx"
#define FILE3_NAME "com-DBLP.mtx"
#define FILE4_NAME "test.mtx"


int main() {

    struct Graph* graph = GenerateGraphFromFile(FILE4_NAME);
    if (graph == NULL) 
    {
        perror("Failed to generate graph.");
        exit(EXIT_FAILURE);
    }
    PrintGraph(graph);
    RunKLAlgorithm(graph);
    DeleteGraph(graph);
    return 0;
}