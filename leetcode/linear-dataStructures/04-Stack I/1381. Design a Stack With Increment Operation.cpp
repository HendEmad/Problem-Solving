class CustomStack {
    vector<int> stack;
    int maxSize;
public:
    CustomStack(int maxSize) {
        this->maxSize = maxSize;
    }
    
    void push(int x) {
        if (stack.size() < maxSize) {
            stack.push_back(x);
        }
    }
    
    int pop() {
        if (stack.empty()) {
            return -1;
        } else {
            int val = stack.back();
            stack.pop_back();
            return val;
        }
    }
    
    void increment(int k, int val) {
        int n = min(k, static_cast<int>(stack.size()));
        for (int i = 0; i < n; ++i) {
            stack[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */