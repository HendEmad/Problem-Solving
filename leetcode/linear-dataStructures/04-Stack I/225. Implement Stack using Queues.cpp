class MyStack {
    queue <int> inputQueue;
    queue <int> outputQueue;


public:
    MyStack() {
        
    }
    
    void push(int x) {
        while(!inputQueue.empty()) {
            outputQueue.push(inputQueue.front());
            inputQueue.pop();
        }
        inputQueue.push(x);
        while(!outputQueue.empty()) {
            inputQueue.push(outputQueue.front());
            outputQueue.pop();
        }
    }
    
    int pop() {
        int top = inputQueue.front();
        inputQueue.pop();
        return top;
    }
    
    int top() {
        return inputQueue.front();
    }
    
    bool empty() {
        return inputQueue.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */