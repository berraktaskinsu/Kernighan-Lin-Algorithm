#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

#include "KLGenerator.h"

#define FILE0_NAME "test.mtx"
#define FILE1_NAME "input_graph.mtx"
#define FILE2_NAME "Erdos02.mtx"
#define FILE3_NAME "com-DBLP.mtx"
#define FILE4_NAME "rgg_n_2_20_s0.mtx"

int initialCutSize;
int finalCutSize;

int main(int argc, char **argv) {
    
    if (argc != 2)
    {
        perror("Invalid arguments");
        exit(EXIT_FAILURE);
    }
    char* fileName = argv[1];
    struct Graph* graph = GenerateGraphFromFile(fileName);
    if (graph == NULL) 
    {
        perror("Failed to generate graph.");
        exit(EXIT_FAILURE);
    }
    //PrintGraph(graph);
    RunKLAlgorithmA(graph);
    finalCutSize = CalculateCutSize(graph);
    printf("\nInitial Cut Size: %d, Final Cut Size: %d\n", initialCutSize, finalCutSize);
    
    RunKLAlgorithmB(graph);
    finalCutSize = CalculateCutSize(graph);
    printf("\nInitial Cut Size: %d, Final Cut Size: %d\n", initialCutSize, finalCutSize);
    
    DeleteGraph(graph);
    return 0;
}