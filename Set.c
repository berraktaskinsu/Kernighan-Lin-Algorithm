#include "Set.h"

struct Set* InitializeSet(int numberOfElements) {
    struct Set* set = (struct Set*) malloc(sizeof(struct Set));
    set -> numberOfElements = numberOfElements;
    set -> iteratorIndex = 0;
    set -> setArray = (struct SetElement*) malloc(numberOfElements * sizeof(struct SetElement));
    for (int index = 0 ; index < numberOfElements ; index++) 
    {
        (set -> setArray)[index].vertex = -1;
    }
    return set;
}

void AddElementToSet(struct Set* set, int vertex) {
    set -> setArray[set -> iteratorIndex].vertex = vertex;
    set -> iteratorIndex ++;
}

void SwitchSubsets(struct Set** sets, struct Set* subsetA, struct Set* subsetB) {

}

void SwitchVertices(struct Set** sets, int vertex1, int vertex2) {

}

void PrintSet(struct Set* set) {
    for (int index = 0 ; index < set -> numberOfElements ; index++) 
    {
        printf("%d ", (set -> setArray)[index].vertex);
    }
    printf("\n");
}

void DeallocateSet(struct Set* set) {
    free(set -> setArray);
    set -> setArray = NULL;
    free(set);
}