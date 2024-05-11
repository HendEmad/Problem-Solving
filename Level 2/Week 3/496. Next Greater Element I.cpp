class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> next_greater;

        // Iterate nums2 from right to left
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            // Pop elements from stack until finding a greater element
            while (!st.empty() && st.top() <= num) {
                st.pop();
            }
            // If there's no greater element, set -1
            if (st.empty()) {
                next_greater[num] = -1;
            } else {  // Otherwise, set the next greater element
                next_greater[num] = st.top();
            }
            // Push current element to stack
            st.push(num);
        }

        // Look up the next greater element for each element in nums1
        vector<int> result;
        for (int num : nums1) {
            result.push_back(next_greater[num]);
        }
        return result;
    }
};