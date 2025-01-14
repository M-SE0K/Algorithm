#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <memory.h>
#include <stdlib.h>

using namespace std;
typedef int ElementType;

typedef struct tageHeapNode{
    ElementType Data;
} HeapNode;

typedef struct tagHeap{
    HeapNode* Nodes;
    int Capacity;       //용량
    int UsedSize;       //힙의 크기
} Heap;

Heap* Heap_Create(int Initialize);
void Heap_Destroy(Heap* h);
void Heap_Insert(Heap* H, ElementType NewData);
void Heap_DeleteMin(Heap* H, HeapNode* Root);
int Heap_GetParent(int Index);
int Heap_GetLeftChild(int Index);
void Heap_SwapNodes(Heap* H, int Index1, int Index2);
void Heap_PrintNodes(Heap* H);

#endif

