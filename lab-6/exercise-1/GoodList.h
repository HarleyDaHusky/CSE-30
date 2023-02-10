#ifndef GOODLIST_H
#define GOODLIST_H

#include <new>
#include <ostream>
#include "ArrayList.h"
#include "Queue.h"
#include "Stack.h"

struct GoodList{
    int* data;
    int capacity;
    int count;

    GoodList(){
        capacity = 1;
        count = 0;
        data = new int[capacity];
    }

    void append(int value){
        data[count] = value;
        count++;

        if(count== capacity){
            int oldCapacity = capacity;
            capacity*=10;

            int* temp = new int[capacity];

            for(int i = 0; i < oldCapacity; i++){
                temp[i] = data[i];
            }

            int* oldLocation = data;
            data = temp;
            delete[] oldLocation;
        }
    }

    int& operator[](int index){
        return data[index];
    }

    ~GoodList(){
        delete[] data;
    }
};

std::ostream& operator<<(std::ostream& os, GoodList& gl){
    for (int i = 0; i < gl.count; i++){
        os << gl.data[i] << " ";
    }
    return os;
}


#endif