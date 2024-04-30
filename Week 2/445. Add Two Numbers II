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
    ListNode* reverseList(ListNode* cur) {
        ListNode* prev = NULL;
        ListNode* fast = cur->next;
        while(cur) {
            // in the first loop current node point NULL and after first loop it points previous node's memory which is prev node
            cur->next = prev;
            // after this prev has to keep being previous node
            prev = cur;
            // meanwhile current point its next pointer which is fast
            cur = fast;
            // fast keeps pointing the next pointer of current if it is available
            if(fast) fast = fast->next;
        }
        return prev;
    }
 
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = reverseList(l1);
        ListNode* r2 = reverseList(l2);
        l1 = r1;
        l2 = r2;
        // sum will be sum of 2 node values and rem stores the value of tenths place integer 
        int sum=0, rem=0;
        ListNode* res = new ListNode();
        
        while(l1 || l2) {
            if(l1) {
                sum += l1->val; 
                l1 = l1->next;
            }
            if(l2) {
                sum += l2->val; 
                l2 = l2->next;
            }
            res->val = sum%10;
            rem = sum/10;
            ListNode* temp = new ListNode(rem);
            temp->next = res;
            res = temp;
            sum = rem;
        }
        // if rem is 0 them it should not be returned
        return rem == 0 ? res->next : res;
    }
};
