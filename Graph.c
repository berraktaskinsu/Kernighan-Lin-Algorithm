#include "Graph.h"

/**
 * @brief Complexity: 
 * 
 * @param vertex1 
 * @param vertex2 
 */

struct Graph* InitializeGraph(int numberOfVertices) {

    // Allocate space for graph (size(int) + size(List*))
    struct Graph* graph = (struct Graph*) malloc (sizeof(struct Graph));
    graph -> numberOfVertices = numberOfVertices;

    // Allocate space for listArray (numberOfVertices * size(List)) = (numberOfVertices * size(Node*))
    graph -> listArray = (struct List*) malloc (numberOfVertices * sizeof(struct List));

    for (int index = 0 ; index < numberOfVertices ; index++) 
    {
        ((graph -> listArray)[index]).head = NULL;
        ((graph -> listArray)[index]).set = 0;
    }

    return graph;
}

void AddEdgeToGraph(struct Graph* graph, int vertex1, int vertex2) {

    int index1 = vertex1 - 1, index2 = vertex2 - 1;
    printf("Adding edge to graph: %d %d\n", index1, index2);

    if (index1 < 0 ||
        index1 >= graph -> numberOfVertices ||
        index2 < 0 ||
        index2 >= graph -> numberOfVertices) 
    {
        char errorMessage[ERR_MESSAGE_LENGTH];
        sprintf(errorMessage, "Invalid Vertices (%d, %d)", vertex1, vertex2);
        fprintf(stderr, "Error on line %d : %s\n", __LINE__, errorMessage);
        exit(EXIT_FAILURE);
    }

    AddNeighbor(graph, index1, vertex2);
    AddNeighbor(graph, index2, vertex1);
}

void PrintGraph(struct Graph* graph) {
    int vertex;
    for (int index = 0 ; index < graph -> numberOfVertices ; index++) 
    {
        vertex = index + 1;

        printf("Vertex %d Set No %d:", vertex, graph ->listArray[index].set);
        struct ListNode* current = ((graph -> listArray)[index]).head;
        while (current != NULL && current -> next != NULL) 
        {
            printf("%d, ", current -> neighbour);
            current = current -> next;
        }
        if (current != NULL) 
        {
            printf("%d\n", current -> neighbour);
        } 
        else 
        {
            printf("Empty\n");
        }
        current = NULL;
    }
}

void AddNeighbor(struct Graph* graph, int index, int neighbour) {
    struct ListNode* node = (struct ListNode*) malloc (sizeof(struct ListNode));
    node -> neighbour = neighbour;
    node -> next = ((graph -> listArray)[index]).head;
    ((graph -> listArray)[index]).head = node;
    node = NULL; // not necessary
}

void DeallocateGraph(struct Graph* graph) {

    for (int index = 0 ; index < graph -> numberOfVertices ; index++) 
    {
        struct ListNode* temp;
        //struct Node* head = &((graph -> listArray)[index]).head;
        while (((graph -> listArray)[index]).head != NULL) 
        {
            temp = ((graph -> listArray)[index]).head;
            ((graph -> listArray)[index]).head = ((graph -> listArray)[index]).head -> next;
            temp -> next = NULL;
            free (temp);
        }
        temp = NULL;
    }
    free (graph -> listArray);
    graph -> listArray = NULL;
    free (graph);
}