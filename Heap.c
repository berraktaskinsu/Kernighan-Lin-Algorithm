
#include "Heap.h"

struct Heap* InitializeHeap(int capacity) {
    struct Heap* heap = (struct Heap*) malloc(sizeof(struct Heap));
    heap -> numberOfElements = 0;
    heap -> capacity = capacity;
    heap -> heapArray = (struct HeapArrayElement*) malloc(capacity * sizeof(struct HeapArrayElement));
    for (int index = 0 ; index < capacity ; index++) 
    {
        (heap -> heapArray)[index].isValid = false;
        (heap -> heapArray)[index].vertex = -1;
        (heap -> heapArray)[index].dValue = -1;
    }
    return heap;
}

void HeapInsert(struct Heap* heap, int vertex, double dValue) {
    int index = heap -> numberOfElements;
    heap -> heapArray[index].isValid = true;
    while (index > 0 && heap -> heapArray[(int) floor(((double) index - 1) / 2.0)].dValue < dValue) 
    {
        // Switch parent and current
        heap -> heapArray[index].dValue = heap -> heapArray[(int) floor(((double) index - 1) / 2.0)].dValue;
        heap -> heapArray[index].vertex = heap -> heapArray[(int) floor(((double) index - 1) / 2.0)].vertex;
        index = (int) floor(((double) index - 1) / 2.0);
        
    }
    heap -> heapArray[index].dValue = dValue;
    heap -> heapArray[index].vertex = vertex;
    heap -> numberOfElements++;
}

struct HeapArrayElement* ExtractMax(struct Heap* heap) {
    struct HeapArrayElement* heapArrayElement = &(heap -> heapArray)[0];
    return heapArrayElement;
}

void PrintHeap(struct Heap* heap) {
    for (int index = 0 ; index < heap -> capacity ; index++) 
    {
        printf("Vertex: %d, D: %d, isValid:%s\n", (heap -> heapArray)[index].vertex, (int) heap ->heapArray[index].dValue, (heap -> heapArray)[index].isValid ? "true" : "false");
    }
}

void DeallocateHeap(struct Heap* heap) {
    free(heap -> heapArray);
    heap -> heapArray = NULL;
    free(heap);
}