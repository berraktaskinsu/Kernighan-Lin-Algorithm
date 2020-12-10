
#include "KLGenerator.h"
/**
 * @brief Complexity: O(c + e*g) e
 *  c: # of lines of comments
 *  e: # of edges
 *  g: # complexity of AddEdgeToGraph()
 * 
 * @param fileName 
 * @return true 
 * @return false 
 */

void RunKLAlgorithm(struct Graph* graph) {

    struct Set** sets = BuildSetsFromGraph(graph);
    PrintSets(sets);
    printf("_______________________Algorithm Started\n");

    // ! STEP1: Calculate D Values, build heap

    int capacity1 = FindNearestPowerOfTwo(sets[0] -> numberOfElements);
    int capacity2 = FindNearestPowerOfTwo(sets[1] -> numberOfElements);
    printf("Capacity of each binary heap: %d, %d\n", capacity1, capacity2);

    struct Heap** heaps = malloc(2 * sizeof(struct Heap*));
    heaps[0] = InitializeHeap(capacity1);
    heaps[1] = InitializeHeap(capacity2);

    

    //double dValue1, dValue2;
    //HeapInsert(heaps[0], dValue1);
    //HeapInsert(heaps[1], dValue2);
    //PrintHeaps(heaps);

    printf("_______________________End\n");
    DeleteHeaps(heaps);
    heaps = NULL;
    DeleteSets(sets);
    sets = NULL;
}

struct Graph* GenerateGraphFromFile(const char* fileName) {
    
    // Open file
    FILE* file; 
    file = fopen(fileName, "r");
    if (file == NULL) 
    {
        perror("Can not open file");
        exit(EXIT_FAILURE);
    }

    struct Graph* graph = NULL;

    // Skip Until First Line
    char* line = NULL;
    long unsigned int size = 0;
    int bytesRead;

    while (true)
    {
        bytesRead = getline(&line, &size, file);
        if (bytesRead == -1) 
        {
            perror("Input file has no data");
            exit(EXIT_FAILURE);
        }
        if (isdigit(line[0])) 
        {
            // Process First Line
            int numberOfVertices, numberOfEdges;
            sscanf(line, "%d %d %d", &numberOfVertices, &numberOfVertices, &numberOfEdges);
            
            graph = InitializeGraph(numberOfVertices);
            // Process Rest of File
            int vertex1, vertex2;
            while (getline(&line, &size, file) != -1) 
            {
                sscanf(line, "%d %d", &vertex1, &vertex2);
                printf("(%d, %d) ", vertex1, vertex2);
                // Add Edge to Graph
                AddEdgeToGraph(graph, vertex1, vertex2);
            }
            break;
        }
    } 

    // Finish Up
    free(line);
    fclose(file);
    return graph;
}

/*
struct Heap** BuildHeapFromGraph(struct Graph* graph) {

    
    int numberOfVertices1 = ceil(((double) (graph -> numberOfVertices)) / 2.0);
    int numberOfVertices2 = floor(((double) (graph -> numberOfVertices)) / 2.0);
    int capacity1 = FindNearestPowerOfTwo(numberOfVertices1);
    int capacity2 = FindNearestPowerOfTwo(numberOfVertices2);
    printf("Capacity of each binary heap: %d, %d\n", capacity1, capacity2);
    if (numberOfVertices1 > capacity1 || numberOfVertices2 > capacity2) {
        perror("numberOfVertices > capacity");
        exit(EXIT_FAILURE);
    }

    struct Heap** heaps = malloc(2 * sizeof(struct Heap*));
    heaps[0] = InitializeHeap(capacity1);
    heaps[1] = InitializeHeap(capacity2);

    int index;
    for (index = 0 ; index < numberOfVertices1 ; index++) {
        AddElementToHeap(heaps[0], index + 1);
    }
    for ( ; index < numberOfVertices1 + numberOfVertices2 ; index++) {
        AddElementToHeap(heaps[1], index + 1);
    }
    return heaps;
}
*/

struct Set** BuildSetsFromGraph(struct Graph* graph) {
    int numberOfVertices1 = ceil(((double) (graph -> numberOfVertices)) / 2.0);
    int numberOfVertices2 = floor(((double) (graph -> numberOfVertices)) / 2.0);

    struct Set** sets = malloc(2 * sizeof(struct Set*));
    sets[0] = InitializeSet(numberOfVertices1);
    sets[1] = InitializeSet(numberOfVertices2);

    int index;
    for (index = 0 ; index < numberOfVertices1 ; index++) {
        AddElementToSet(sets[0], index + 1);
    }
    for ( ; index < numberOfVertices1 + numberOfVertices2 ; index++) {
        AddElementToSet(sets[1], index + 1);
    }
    return sets;
}

void PrintSets(struct Set** sets) {
    printf("Set 1: ");
    PrintSet(sets[0]);
    printf("Set 2: ");
    PrintSet(sets[1]);
}

void PrintHeaps(struct Heap** heaps) {
    printf("Heap 1:\n");
    PrintHeap(heaps[0]);
    printf("Heap 2:\n");
    PrintHeap(heaps[1]);
}

void DeleteGraph(struct Graph** graph) {
    DeallocateGraph(*graph);
    *graph = NULL;
}

void DeleteSets(struct Set** sets) {
    DeleteSet(sets[0]);
    DeleteSet(sets[1]);
    sets[0] = NULL;
    sets[1] = NULL;
    free(sets);
}

void DeleteSet(struct Set* set) {
    DeallocateSet(set);
}

void DeleteHeaps(struct Heap** heaps) {
    DeleteHeap(heaps[0]);
    DeleteHeap(heaps[1]);
    heaps[0] = NULL;
    heaps[1] = NULL;
    free(heaps);
}

void DeleteHeap(struct Heap* heap) {
    DeallocateHeap(heap);
}