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

void AddElementToHeapSet(struct Heap* heap, int vertex);

// ! NOT NECESSARY
//void HeapInsert(struct Heap* heap, int vertex, double dValue);

// ! INPUT: Vertex or Index?
//void HeapDelete(struct Heap* heap, int vertex);

// TODO: Implement
void Heapify(struct Heap* heap, int index);

// TODO: Implement
void BuildHeap(struct Heap* heap);

// TODO: Implement
struct HeapArrayElement* ExtractMax(struct Heap* heap);

void PrintHeap(struct Heap* heap);

void DeallocateHeap(struct Heap* heap);

#endif