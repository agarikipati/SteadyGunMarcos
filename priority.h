#ifndef PRIORITY_H
#define PRIORITY_H

#include "dynamicarray.h"

template <class T>
class priority_queue{
public:
    priority_queue();
    void Insert(T toAdd);
    T GetNext();
    T& Peek();
    bool IsEmpty();
    int Size();
    bool IsHeap(int index);
    void Print();
private:
    int Parent(int index);
    int Left(int index);
    int Right(int index);
    void Heapify(int index);
    void BuildHeap();
    int size;
    dynamicArray<T> objects;
};

#include "priority.cpp"

#endif
