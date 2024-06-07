class FrontMiddleBackQueue {
    deque<int>dq;
    stack<int>s;
public:
    FrontMiddleBackQueue() {}
    
    void pushFront(int val) {
        dq.push_front(val);
    }
    
    void pushMiddle(int val) {
        int n=dq.size()/2;
        for(int i=0;i<n;i++)
        {
            s.push(dq.front());
            dq.pop_front();
        }
        dq.push_front(val);
        while(!s.empty())
        {
            dq.push_front(s.top());
            s.pop();
        }
    }
    
    void pushBack(int val) {
        dq.push_back(val);
    }
    
    int popFront() {
        int ans=-1;
        if(!dq.empty()){
            ans=dq.front();
            dq.pop_front();
        }
        return ans;
    }
    
    int popMiddle() {
        if(dq.empty())
        return -1;
        int n=dq.size();
        if(n%2==0)
        n=(dq.size()/2)-1;
        else
        n=dq.size()/2;
        for(int i=0;i<n;i++)
        {
            s.push(dq.front());
            dq.pop_front();
        }
        int ans=dq.front();
        dq.pop_front();
        while(!s.empty())
        {
            dq.push_front(s.top());
            s.pop();
        }
        return ans;
    }
    
    int popBack() {
        int ans=-1;
        if(!dq.empty())
        {
            ans=dq.back();
            dq.pop_back();
        }
        return ans;
    }
};