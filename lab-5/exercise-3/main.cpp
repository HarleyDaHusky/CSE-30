#include <iostream>
#include <stdexcept>
#include <string>
#include "Queue.h"
#include "Stack.h"

using namespace std;

/*
Total jobs: 4
User: Alice
Time for user: 125
User: Bob
Time for user: 103
User: Cecilia
Time for user: 77
User: David
Time for user: 83
*/

int main(){
    Queue<string> names;
    Queue<int> totalTime;

    int jobCount;
    cout<<"Enter total amount of jobs: "<<endl;
    cin >> jobCount;
    for (int i = 0; i < jobCount; i++){
        string name;
        int time;
        cout<< "Enter user's name: "<<endl;
        cin >> name;
        names.enqueue(name);
        cout<<"Enter total time for user: "<<endl;
        cin >> time;
        totalTime.enqueue(time);

        cout << name << " : " << time << endl;
    }
    int period;
    cout<<"Enter total time period"<<endl;
    cin >> period;

    while(names.length() != 0){
        int namesLen = names.length();
        for(int i = 0; i < namesLen; i++){
            int timeLeft;
            if(totalTime.peek() >= 25){
                cout<<names.peek()<<" - "<<period<<endl;                
                timeLeft = (totalTime.peek())-period;
                names.enqueue(names.dequeue());
                totalTime.enqueue(timeLeft);
                totalTime.dequeue();
            }
            else{
                if(totalTime.peek() == 0){
                    names.dequeue();
                    totalTime.dequeue();
                }
                else{
                    timeLeft = totalTime.peek();
                    cout<<names.dequeue()<<" - "<<totalTime.dequeue()<<endl;    
                }                            
            }
        }
    }

    cout << "Done..." << endl;


    
    return 0;
}