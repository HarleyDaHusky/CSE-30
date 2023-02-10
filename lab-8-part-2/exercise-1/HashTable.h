#ifndef HASH_TABLE_H
#define HASH_TABLE_H

#include "ArrayList.h"
#include "LinkedList.h"
#include <string>

struct HashTable{

    // You can declare more instance variables here
    int K;

    ArrayList<LinkedList<int>*> storage;

    HashTable(){
        K = 10;
        for(int i = 0; i < K; i++){
            storage.append(new LinkedList<int>);
        }
        //count = 0;
    }

    HashTable(int K){
        this -> K = K; //set the input K to the attribute K of the struct HashTable by using pointer "this"
        for(int i = 0; i < K; i++){
            storage.append(new LinkedList<int>);
        }
        //count = 0;
    }

    void add(int value){
        int index = value % K; //Use K instead of 10
        storage[index]->append(value);
    }


    bool search(int value){
        //first check if value is valid
        if (value<0){
            return false;
        }
        int index = value % K; //Use K instead of 10
        bool item = storage[index]->search(value); //search returns true or false
        return item;
    }

    // You can declare other functions if needed

};

#endif