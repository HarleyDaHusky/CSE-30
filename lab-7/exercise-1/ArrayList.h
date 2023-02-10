// This file will contain part of your solution
#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>
#include <ostream>
#include <stdexcept>

using namespace std;

template <class T>
struct ArrayList{
private:
    T* data;
    int capacity;
    int count;
    int* temp;

// Helper functions
    void swap(const int& index1, const int& index2){
        int temp = data[index1];
        data[index1] = data[index2];
        data[index2] = temp;
    }

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

    int findMinPos(int start){
        int minPos = start;
        int minVal = data[start];

        for(int i = start+1; i < count; i++){
            if(data[i] < minVal){
                minVal = data[i];
                minPos = i;
            }
        }

        return minPos;
    }

    void selection_sort(){
        for(int i = 0; i < count-1; i++){
            int j = findMinPos(i);
            int temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
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

                    
public:
    ArrayList(){
        capacity = 1;
        count = 0;
        data = new T[capacity];
    }

    ArrayList(const ArrayList<T>& other){
        count = other.count;
        capacity = other.capacity;

        data = new T[capacity];
        for (int i = 0; i < count; i++){
            data[i] = other.data[i];
        }
    }

    ArrayList<T>& operator=(const ArrayList<T>& other){
        T* oldData = data;
        count = other.count;
        capacity = other.capacity;

        data = new T[capacity];
        for (int i = 0; i < count; i++){
            data[i] = other.data[i];
        }
        delete[] oldData;
    }

    T& operator[](int index){
        return data[index];
    }

    T& get(int index) const{
        return data[index];
    }

    bool operator==(const ArrayList<T>& other) const{
        if (count != other.count){
            return false;
        }

        for (int i = 0; i < count; i++){
            if(data[i] != other.data[i]){
                return false;
            }
        }
        return true;
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

    int size() const{
        return count;
    }

    bool search(const T& value){
        return binary_search(value);
    }

    void sort(int algo){
        if (algo == 1){
            selection_sort();
        }
        else if(algo == 2){
            insertion_sort();
        }
        else if (algo == 3){
            quick_sort();
        }
    }

    ~ArrayList(){
        delete[] data;
    }
};

template <class T>
std::ostream& operator<<(std::ostream& os, const ArrayList<T>& list){
    for (int i = 0; i < list.size(); i++){
        os << list.get(i) << " ";
    }

    return os;
}

#endif