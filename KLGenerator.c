
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

    struct Heap** heaps = BuildHeapSetsFromGraph(graph);
    PrintHeaps(heaps);
    printf("_______________________Algorithm Started\n");

    // ! STEP1: Calculate D Values, build heap

    /**
     * @brief Create the Initial Heaps
     * 
     *  Find d values of each vertex in the sets and add them to the corresponding set
     * ! Do we really need Set class, won't heap be enough?
     */
    double dValue;
    int vertex, myCount, yourCount;
    for (int setNo = 1 ; setNo < 3 ; setNo++) {
        for (int index = 0 ; index < heaps[setNo - 1] -> numberOfElements ; index++) 
        {
            myCount = 0;
            yourCount = 0;
            vertex = heaps[setNo - 1] -> heapArray[index].vertex;
            struct ListNode* current = graph -> listArray[vertex - 1].head;
            
            while (current != NULL) 
            {
                if (graph -> listArray[current -> neighbour - 1].set == setNo) {
                    myCount++;
                } 
                else
                {
                    yourCount++;
                }
                current = current -> next;
            }
            dValue = yourCount - myCount;
            printf("Set No: %d, Vertex: %d, D: %d\n", setNo, vertex, (int)dValue);
            heaps[setNo - 1] -> heapArray[index].dValue = dValue;
        }
    }
    BuildHeap(heaps[0]);
    BuildHeap(heaps[1]);
    PrintHeaps(heaps);

    


    printf("_______________________End\n");
    DeleteHeaps(heaps);
    heaps = NULL;
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
struct Set** BuildSetsFromGraph(struct Graph* graph) {
    int numberOfVertices1 = ceil(((double) (graph -> numberOfVertices)) / 2.0);
    int numberOfVertices2 = floor(((double) (graph -> numberOfVertices)) / 2.0);

    struct Set** sets = malloc(2 * sizeof(struct Set*));
    sets[0] = InitializeSet(numberOfVertices1);
    sets[1] = InitializeSet(numberOfVertices2);

    int index;
    for (index = 0 ; index < numberOfVertices1 ; index++) {
        AddElementToSet(sets[0], index + 1);
        graph -> listArray[index].set = 1;
    }
    for ( ; index < numberOfVertices1 + numberOfVertices2 ; index++) {
        AddElementToSet(sets[1], index + 1);
        graph -> listArray[index].set = 2;
    }
    
    return sets;
}
*/
struct Heap** BuildHeapSetsFromGraph(struct Graph* graph) {
    int numberOfVertices1 = ceil(((double) (graph -> numberOfVertices)) / 2.0);
    int numberOfVertices2 = floor(((double) (graph -> numberOfVertices)) / 2.0);
    //int capacity1 = FindNearestPowerOfTwo(numberOfVertices1);
    //int capacity2 = FindNearestPowerOfTwo(numberOfVertices2);
    struct Heap** heapSets = malloc(2 * sizeof(struct Heap*));
    heapSets[0] = InitializeHeap(numberOfVertices1);
    heapSets[1] = InitializeHeap(numberOfVertices2);

    int index;
    for (index = 0 ; index < numberOfVertices1 ; index++) {
        AddElementToHeapSet(heapSets[0], index + 1);
        graph -> listArray[index].set = 1;
    }
    for ( ; index < numberOfVertices1 + numberOfVertices2 ; index++) {
        AddElementToHeapSet(heapSets[1], index + 1);
        graph -> listArray[index].set = 2;
    }
    return heapSets;
}

/*void PrintSets(struct Set** sets) {
    printf("Set 1: ");
    PrintSet(sets[0]);
    printf("Set 2: ");
    PrintSet(sets[1]);
}*/

void PrintHeaps(struct Heap** heaps) {
    printf("Heap 1:\n");
    PrintHeap(heaps[0]);
    printf("Heap 2:\n");
    PrintHeap(heaps[1]);
}

void DeleteGraph(struct Graph* graph) {
    DeallocateGraph(graph);
}

/*void DeleteSets(struct Set** sets) {
    DeleteSet(sets[0]);
    DeleteSet(sets[1]);
    sets[0] = NULL;
    sets[1] = NULL;
    free(sets);
}

void DeleteSet(struct Set* set) {
    DeallocateSet(set);
}*/

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