class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> res;
        ListNode* temp = head;
        int cnt = 0;
        
    
        while (temp != nullptr) {
            cnt++;
            temp = temp->next;
        }
        
        temp = head;

        if (k >= cnt) {
       
            for (int i = 0; i < cnt; i++) {
                ListNode* node = new ListNode(temp->val);
                res.push_back(node);
                temp = temp->next;
            }
            for (int i = cnt; i < k; i++) {
                res.push_back(nullptr);
            }
        }
        else {
            int quotient = cnt / k;
            int remainder = cnt % k;
            
            for (int i = 0; i < k; i++) {
                ListNode* node = new ListNode(-1);
                ListNode* current = node;
                for (int j = 0; j < quotient + (i < remainder ? 1 : 0); j++) {
                    if (temp != nullptr) {
                        current->next = new ListNode(temp->val);
                        current = current->next;
                        temp = temp->next;
                    }
                }
                res.push_back(node->next); 
            }
        }
        
        return res;
    }
};
