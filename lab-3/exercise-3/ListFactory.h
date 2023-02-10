#ifndef LIST_FACTORY_H
#define LIST_FACTORY_H

#include <ostream>
#include <string>
#include "AbstractList.h"
#include "ArrayList.h"
#include "LinkedList.h"

struct ListFactory : public AbstractList{
    static AbstractList* create(std::string name){
        if (name == "ArrayList"){
            return new ArrayList();
        }
        else if(name == "LinkedList"){
            return new LinkedList();
        }
        else{
            return nullptr;
        }
    }
};

// This allows us to print LinkedList and ArrayList objects
std::ostream& operator<<(std::ostream& os, AbstractList* list){
    if (typeid(*list).name() == typeid(LinkedList).name()){
        os << *((LinkedList*)list);
    }
    else if (typeid(*list).name() == typeid(ArrayList).name()){
        os << *((ArrayList*)list);
    }
    else{
        os << "Can't print this list";
    }

    return os;
}

#endif