// This file will contain part of your solution
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
#include <ostream>
#include <stdexcept>
template <class T>
struct ArrayList{
private:
    T* data;
    int capacity;
    int count;

// Helper functions

    bool linear_search(const T& value){
        for (int i = 0; i < count; i++){
            if (data[i] == value){
                return true;
            }
        }
        return false;
    }

    bool binary_search(const T& value){
        int left = 0;
        int right = count;

        while (left <= right){
            int mid = (left + right) / 2;
            if (data[mid] == value){
                return true;
            }
            else if (data[mid] > value){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return false;
    }

    void quickSortHelper(int left, int right){
        int i = left;
        int j = right;
        int temp;
        int pivot = data[(left+right)/2];
        while(i <= j){
            while(data[i] < pivot){
                i++;
            }
            while(data[j] > pivot){
                j--;
            }
            if(i <= j){
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
                i++;
                j--;
            }
        }

        if(left < j){
            quickSortHelper(left, j);
        }
        if(i < right){
            quickSortHelper(i, right);
        }
    }

    void quick_sort(){
        quickSortHelper(0, count-1);
    }    

    void insertion_sort(){
        int i;
        int key;
        int j;
        for(int i = 1; i < count; i++){
            key = data[i];
            j = i-1;
            while(j>=0 and data[j] > key){
                data[j+1] = data[j];
                j = j-1;
            } 
            data[j+1] = key;
        }
    }

public:
    ArrayList(){
        capacity = 1;
        count = 0;
        data = new T[capacity];
    }

    void append(T value){
        data[count] = value;
        count++;

        if (count == capacity){

            int oldCapacity = capacity;
            capacity *= 2;

            T* temp = new T[capacity];

            for (int i = 0; i < oldCapacity; i++){
                temp[i] = data[i];
            }

            T* oldLocation = data;
            data = temp;
            delete[] oldLocation;
        }
    }

    void add(T value){
        data[count] = value;
        count++;
        if(count == capacity){
            int oldCapacity = capacity;
            capacity *=10;
            T* temp = new T[capacity];
            for(int i = 0; i < oldCapacity; i++){
                temp[i] = data[i];
            }
            T* oldLocation = data;
            data = temp;
            delete[] oldLocation;
        }
       quick_sort();
    }

    int size() const{
        return count;
    }

    T& operator[](int index){
        return data[index];
    }

    bool search(const T& value){
        return binary_search(value);
    }

    ~ArrayList(){
        delete[] data;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, ArrayList<T>& list){
    for (int i = 0; i < list.size(); i++){
        os << list[i] << " ";
    }

    return os;
}

#endif