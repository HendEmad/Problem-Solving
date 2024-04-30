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
    ListNode* reverse(ListNode* head){
        ListNode* current = head;
        ListNode *prev = NULL, *nxt = NULL;
        
        while(current!=NULL){
            nxt = current->next;
            current->next = prev;
            prev = current;
            current = nxt;
        }

        return prev; 
    }


    int getDecimalValue(ListNode* head) {
        head = reverse(head);
        ListNode* node = head;
        int value=0;
        long int pow = 1;

        while(node!=NULL){
            value+=node->val * pow;
            pow *= 2;
            node = node->next;  
        }

        return value;
    }
};
