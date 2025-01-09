#include<iostream>
using namespace std;
//  Queue class
class Queue{
private:
    int *arr;
    int frontIndex;
    int rearIndex;
    int capacity;

public:
    Queue(int size =5){
        capacity = size;
        arr = new int[capacity];
        frontIndex = -1;
        rearIndex =-1;
    }
    ~Queue(){
        delete[]arr;
    }
    // Make the queue empty 
    void makenull(){
        frontIndex = -1;
        rearIndex = -1;
    }
    // Check if the queue is empty
    bool empty() const{
        return frontIndex == -1;
        }
    // Get the front element
    int front() const {
        if (empty()){
            cout << "Queue is empty!" << endl;
            return - 1;
        }
        return arr[frontIndex];

    }
    // Add an element to the rear
    void enqueue(int value){
        if((rearIndex + 1) % capacity == frontIndex){
            // Queue is full  
            cout << "Queue is full, resizing..." << endl;
            resize();
        }
        if  (empty()) frontIndex = 0;
        rearIndex = (rearIndex + 1) % capacity;
        arr[rearIndex] = value;
    
    }
    // Remove an element from the front
    void dequeue() 
    {
        if  (empty()){
            cout << "Queue is empty, nothing to dequeue!" << endl;
            return;
        }
        if  (frontIndex == rearIndex) 
        {
            // Only one element 
            makenull();
        }
        else{
            frontIndex = (frontIndex + 1) % capacity;
        }
    }

private:
    void resize(){
        int newCapacity = capacity * 2;
        int * newArr = new int[newCapacity];
        int i = frontIndex, j = 0;
        do 
        {
            i = (i + 1) % capacity;
        
            delete[] arr;
            newArr[j++] = arr[i];
            arr = newArr;
            frontIndex = 0;
        }
        while (i != (rearIndex + 1) % capacity);
        rearIndex = j - 1;
        capacity = newCapacity;
    
    }
};
int main(){
    // Queue demonstration
    Queue queue;
    cout << "Queue operations:" << endl;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    cout << "Front element: " << queue.front() << endl;
    queue.dequeue();
    cout << "Front element after dequeue: " << queue.front() << endl;
    queue.makenull();
    cout << "Queue is " << (queue.empty() ? "empty" : "not empty") << endl;
    cout << "\n";
     
   
    
}