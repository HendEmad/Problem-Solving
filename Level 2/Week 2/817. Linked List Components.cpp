/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        // n = no of node in list
        // m = size of num

        unordered_set<int> st; 
        for(int it:nums) 
            st.insert(it);


        int comp = 0;
        bool flag = false;

        while(head){       
            if(st.count(head->val)){  
                if(!flag)
                    comp++;

                flag = true;
            }
            else
                flag = false;
            
            head = head->next;
        }
        return comp;
    }
};
