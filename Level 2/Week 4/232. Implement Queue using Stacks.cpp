class MyQueue {
    stack <int> inputStack;
    stack <int> outputStack;

    // A function to move elements from inputStack to outputStack
    void moveElements () {
        if (outputStack.empty()) {
            while(!inputStack.empty()) {
                outputStack.push(inputStack.top());
                inputStack.pop();
            }
        }
    }

public:
    MyQueue() {
        
    }
    
    void push(int x) {
        inputStack.push(x);    
    }
    
    int pop() {
        moveElements();
        int front = outputStack.top();
        outputStack.pop();
        return front;
    }
    
    int peek() {
        moveElements();
        return outputStack.top();
    }
    
    bool empty() {
        return (inputStack.empty() && outputStack.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */