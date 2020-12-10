#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "Helper.h"

#ifndef __HEAP_H__
#define __HEAP_H__

struct HeapArrayElement {
    bool isValid;
    int vertex;
    double dValue;
};

struct Heap {
    int numberOfElements;
    int capacity;
    struct HeapArrayElement* heapArray;
};

struct Heap* InitializeHeap(int capacity);

void HeapInsert(struct Heap* heap, int vertex, double dValue);

// TODO: Implement
struct HeapArrayElement* ExtractMax(struct Heap* heap);

void AddElementToHeap(struct Heap* heap, int vertex);

// TODO: Implement
void PrintHeap(struct Heap* heap);

void DeallocateHeap(struct Heap* heap);

#endif