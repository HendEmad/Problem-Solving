/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s[0] != '[') return NestedInteger(stoi(s)); // if string contains single number ex: "123".
    
        vector<NestedInteger> v; // using vector to simulate stack
        string num = ""; // num will store the number, number can be negative or positive.
    
        for(auto c: s){
            if(c == '['){
                v.push_back(NestedInteger());
            }
            else if(c == ']' or c == ','){
                if(num != ""){
                    v.back().add(NestedInteger(stoi(num)));
                    num = "";
                }
            
                if(c == ']' and v.size() >= 2){
                    NestedInteger ni = v.back();
                    v.pop_back();
                    v.back().add(ni);
                }
            }
            else num.push_back(c); // if c is a digit just add to num.
        }
    
        return v.back();
    }
};