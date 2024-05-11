class StockSpanner {
public:
    stack <pair<int, int>> st;
    int count = 1;
    StockSpanner() {}
    
    int next(int price) {
        int ans;
        if(st.empty()) {
            st.push({price, count});
            ans = 1;
        }
        else if(!st.empty() && st.top().first > price) {
            ans = count - st.top().second;
        }
        else if (!st.empty() && st.top().first <= price) {
            while(!st.empty() && st.top().first <= price) {
                st.pop();
            }
            if(st.empty()) {
                ans = count;
            }
            else {
                ans = count - st.top().second;
            }
        }
        st.push({price, count});
        count++;

        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */