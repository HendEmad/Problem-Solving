/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    vector<int> ans;
    int k=0;

    void solve(vector<NestedInteger> &n){
        for(int i=0;i<n.size();i++){
            if(n[i].isInteger())
                ans.push_back(n[i].getInteger());
            else 
               solve(n[i].getList()); 
        }
    }

    NestedIterator(vector<NestedInteger> &nestedList) {
        solve(nestedList);
    }

    
    int next() {
        return ans[k++];
    }
    
    bool hasNext() {
        if(k<ans.size()) 
            return true;
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
