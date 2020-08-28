#pragma once
#include "SimpleHeap.h"

template<typename T>
class PriorityQueue :
    public Heap<T>
{
public:
    PriorityQueue(Heap<T>::PriorityComp pc)
        :Heap<T>::Heap(pc)
    {}

    int PQIsEmoty() {
        return Heap<T>::HisEmoty();
    }

    void PEnqueue(T data) {
        Heap<T>::HInsert(data);
    }

    T PDequeue() {
        return Heap<T>::HDelete();
    }
};

