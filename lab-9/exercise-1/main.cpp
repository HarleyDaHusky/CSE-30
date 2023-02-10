#include <iostream>
#include "BSTNode.h"
#include "support.h"
#include "ArrayList.h"

using namespace std;



int main(){
    ArrayList<int> expectedPath;
    expectedPath.append(8);
    expectedPath.append(7);
    expectedPath.append(10);
    expectedPath.append(5);
    
    BSTNode* tree = nullptr;

    tree = insert(tree, 5);
    tree = insert(tree, 3);
    tree = insert(tree, 10);
    tree = insert(tree, 20);
    tree = insert(tree, 7);
    tree = insert(tree, 8);


    draw(tree);

    BSTNode* test = search(tree, 8);

    ArrayList<int> test_path = pathToRoot(tree, test);

    if (test_path == expectedPath){
        cout << "It works" << endl;
    }
    else{
        cout << "Something went wrong" << endl;
    }

    return 0;
}