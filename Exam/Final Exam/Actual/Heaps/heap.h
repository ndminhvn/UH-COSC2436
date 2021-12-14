#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

void heapify(int *data, int size, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
 
    if (l < size && data[l] > data[largest])
        largest = l;

    if (r < size && data[r] > data[largest])
        largest = r;
 
    if (largest != i) {
        swap(data[i], data[largest]);
        heapify(data, size, largest);
    }
}

void heapify(int *data, int size)
{
    int start = (size / 2) - 1;

    for(int i = start; i >= 0; i--){
        heapify(data, size, i);
    }
}

// DO NOT MODIFY CODE BELOW THIS LINE

bool is_maxheap ( int *data, int size, int pos=0 )
{
    int child1 = 2*pos+1;
    int child2 = 2*pos+2;
    bool b1=true, b2=true;
    bool result = true;

    if ( child1 < size ) {
        if  ( data[pos] < data[child1] || !is_maxheap(data, size, child1) ){
            b1 = false;
        }
    }
    if ( child2 < size ) {
        if ( data[pos] < data[child2] || !is_maxheap ( data, size, child2 ) ) {
            b2 = false;
        }
    }

    if ( !b1 || !b2 )
        result = false;

    return result;
}

void print_data(int *data, int size)
{
    cout << "    ";
    for ( int i=0; i<size; i++ ) {
        cout << data[i] << " ";
    }
    cout << std::endl;
}
#endif