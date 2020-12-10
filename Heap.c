
#include "Heap.h"

struct Heap* InitializeHeap(int capacity) {
    struct Heap* heap = (struct Heap*) malloc(sizeof(struct Heap));
    heap -> numberOfElements = 0;
    heap -> capacity = capacity;
    heap -> heapArray = (struct HeapArrayElement*) malloc(capacity * sizeof(struct HeapArrayElement));
    for (int index = 0 ; index < capacity ; index++) {
        (heap -> heapArray)[index].isValid = false;
        (heap -> heapArray)[index].vertex = -1;
        (heap -> heapArray)[index].dValue = -1;
    }
    return heap;
}

void HeapInsert(struct Heap* heap, int id, double key) {
    int index = heap -> numberOfElements;
    heap -> heapArray[index].isValid = true;
    while (index > 0 && heap -> heapArray[(int) floor(((double) index + 1) / 2.0)].dValue < key) {
        heap -> heapArray[index].dValue = heap -> heapArray[(int) floor(((double) index + 1) / 2.0)].dValue;
        heap -> heapArray[index].vertex = heap -> heapArray[(int) floor(((double) index + 1) / 2.0)].vertex;
        index = (int) floor(((double) index + 1) / 2.0);
        
    }
    heap -> heapArray[index].dValue = key;
    heap -> heapArray[index].vertex = id;
    heap -> numberOfElements++;
}

struct HeapArrayElement* ExtractMax(struct Heap* heap) {
    struct HeapArrayElement* heapArrayElement = &(heap -> heapArray)[0];
    return heapArrayElement;
}

void AddElementToHeap(struct Heap* heap, int vertex) {
    heap -> heapArray[heap -> numberOfElements].isValid = true;
    heap -> heapArray[heap -> numberOfElements].vertex = vertex;
    heap -> heapArray[heap -> numberOfElements].dValue = 0;
    heap -> numberOfElements ++;
}

void PrintHeap(struct Heap* heap) {
    for (int index = 0 ; index < heap -> capacity ; index++) {
        printf("%d, isValid:%s\n", (heap -> heapArray)[index].vertex, (heap -> heapArray)[index].isValid ? "true" : "false");
    }
}

void DeallocateHeap(struct Heap* heap) {
    free(heap -> heapArray);
    heap -> heapArray = NULL;
    free(heap);
}