#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <limits.h>

#include "Graph.h"
#include "Heap.h"
#include "Set.h"

#ifndef __KLGENERATOR_H__
#define __KLGENERATOR_H__

void RunKLAlgorithm(struct Graph* graph);

struct Graph* GenerateGraphFromFile(const char* fileName);

// TODO: Implement
//struct Heap** BuildHeapFromGraph(struct Graph* graph);
struct Set** BuildSetsFromGraph(struct Graph* graph);

void PrintSets(struct Set** sets);

void PrintHeaps(struct Heap** heaps);

void DeleteGraph(struct Graph** graph);

void DeleteSets(struct Set** sets);

void DeleteSet(struct Set* set);

void DeleteHeaps(struct Heap** heaps);

void DeleteHeap(struct Heap* heap);

#endif