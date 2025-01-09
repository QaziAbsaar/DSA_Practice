 #include<iostream>
 using namespace std;
 //  Stack class
class Stack{
private:
    int * arr;
    int topIndex;
    int capacity;

public:
    Stack(int size = 5) 
    {
        capacity = size;
        arr = new int[capacity];
        topIndex = - 1;
        
    }
    ~Stack() 
    {
        delete[] arr;
        
    }
    // Make the stack empty 
     void makenull() 
    {
        topIndex = - 1;
        
    }
    // Check if the stack is empty 
     bool empty() const 
    {
     return topIndex == - 1;
        
    }
    // Get the top element 
     int top() const 
    {
        if  (empty()) 
        {
            cout << "Stack is empty!" << endl;
            return - 1;
        }
        return arr[topIndex];
    
    }
    // Push an element onto the stack  
    void push(int value) 
    {
        if  (topIndex + 1 == capacity) 
        {
            // Stack is full 
            cout << "Stack is full, resizing..." << endl;
            resize();
        }
        arr[++topIndex] = value;
       
    }
    // Pop an element from the stack 
    void pop() 
    {
        if  (empty()) 
        {
            cout << "Stack is empty, nothing to pop!" << endl;
            return;
        }
        topIndex--;
        
    }

private:
    void resize() 
    {
        int newCapacity = capacity * 2;
        int * newArr = new int[newCapacity];
        for (int i = 0; i <= topIndex; i++) 
        {
           newArr[i] = arr[i];
         
        }
        delete[] arr;
        arr = newArr;
        capacity = newCapacity;
       
    }
};
int main(){
    // Stack demonstration
    Stack stack;
    cout << "Stack operations:" << endl;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    cout << "Top element: " << stack.top() << endl;
    stack.pop();
    cout << "Top element after pop: " << stack.top() << endl;
    stack.makenull();
    cout << "Stack is " << (stack.empty() ? "empty" : "not empty") << endl;
   
    return 0 ;

}