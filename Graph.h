#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Helper.h"

#ifndef __GRAPH_H__
#define __GRAPH_H__

struct ListNode
{
    int neighbour;
    struct ListNode* next;
};

struct List
{
    int set;
    struct ListNode* head;
};

struct Graph
{
    int numberOfVertices;
    struct List* listArray;
};

struct Graph* InitializeGraph(int numberOfVertices);

void AddEdgeToGraph(struct Graph* graph, int vertex1, int vertex2);

void AddNeighbor(struct Graph* graph, int index, int vertex);

bool EdgeExists(struct Graph* graph, int vertex1, int vertex2);

void PrintGraph(struct Graph* graph);

void DeallocateGraph(struct Graph* graph);

#endif