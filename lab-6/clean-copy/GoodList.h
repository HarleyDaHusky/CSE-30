#ifndef GOODLIST_H
#define GOODLIST_H

#include <ostream>


struct GoodList{

    GoodList(){
        // Your code here
    }

    void append(int value){
        // Your code here
    }

    int& operator[](int index){
        // Your code here
    }

    ~GoodList(){
        // Your code here
    }
};

std::ostream& operator<<(std::ostream& os, GoodList& gl){

    // Your code here

    return os;
}


#endif