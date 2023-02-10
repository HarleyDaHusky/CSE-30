#include <iostream>
#include "Queue.h"
#include "Stack.h"

using namespace std;

int main(){

    int op;
    int total = 0;
    int amount;
    Stack<string> operations;
    Stack<int> values;      

    do{
        cout << "1. Add" << endl;
        cout << "2. Subtract" << endl;
        cout << "3. Multiply" << endl;
        cout << "4. Divide" << endl;
        cout << "5. Undo" << endl;
        cout << "6. Stop" << endl;
        cout << endl;
        cout << "Select option: ";
        cin >> op;      

        if (op == 1){
            cout << "Enter amount: ";
            cin >> amount;
            values.push(amount);
            operations.push("+");
            total += amount;
        }
        else if (op == 2){
            cout << "Enter amount: ";
            cin >> amount;
            values.push(amount);
            operations.push("-");            
            total -= amount;
        }
        else if (op == 3){
            cout << "Enter amount: ";
            cin >> amount;
            values.push(amount);
            operations.push("*");            
            total *= amount;
        }
        else if (op == 4){
            cout << "Enter amount: ";
            cin >> amount;
            values.push(amount);
            operations.push("/");            
            total /= amount;
        }
        else if (op == 5){

            if(operations.peek() == "+"){
                total -= values.peek();
            }
            else if(operations.peek() == "-"){
                total += values.peek();
            }
            else if(operations.peek() == "*"){
                total /= values.peek();
            }
            else if(operations.peek() == "/"){
                total *= values.peek();
            }
            operations.pop();
            values.pop();                                            
            cout << "Will undo last operation" << endl;
        }
        
        cout << endl << "Total: " << total << endl << endl;
    }
    
    while( op != 6);
    cout << "Done..." << endl;

    return 0;
}