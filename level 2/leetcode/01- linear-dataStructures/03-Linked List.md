<details>
<summary><strong><a href = "https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/">1290.convert binary number in a linked list to integer</a></strong></summary>

```cpp
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
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/delete-node-in-a-linked-list/">237.delete node in a linked list</a></strong></summary>

```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) 
    {
        node->val = node->next->val;
        node->next = node->next->next ;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/add-two-numbers-ii/">445.add two numbers ii</a></strong></summary>

```cpp
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
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/merge-in-between-linked-lists/">1669.merge in between linked lists</a></strong></summary>

```cpp
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

    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* p = list1;
        ListNode* q = list1;
        ListNode* r = list2;

        while(r->next!=NULL)
            r = r->next;

        a = a-1; 

        while(a > 0)
        {
            p = p->next;
            a--;
        }

        b+=1;

        while(b>0)
        {
            q = q->next;
            b--;
        }

        p->next = list2; 
        r->next = q; 
        
        return list1;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/swapping-nodes-in-a-linked-list/">1721.swapping nodes in a linked list</a></strong></summary>

```cpp
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
    ListNode* swapNodes(ListNode* head, int k) {
        
        ListNode*temp=head;
        int count =0;
        while(temp!=NULL){
            temp=temp->next;
            count++;
        }
         ListNode*temp1=head;
          ListNode*temp2=head;
        int x=count-k;
        while(k!=1){
            temp1=temp1->next;
            k--;
        }
        while(x!=0){
            temp2=temp2->next;
            x--;
        }
        int swp=temp1->val;
        temp1->val=temp2->val;
        temp2->val=swp;
        return head;

    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/design-linked-list/">707.design linked list</a></strong></summary>

```cpp
class Node {
  public:
    int val;
    Node* next;
    Node(int x): val(x), next(nullptr) {}
};

class MyLinkedList {
public:
    Node* head;
    int size;
    MyLinkedList(): head(nullptr), size(0) {}
	    
    int get(int index) {
        // Return -1 for invalid index
        if(index>=size || index < 0) 
            return -1;

        Node* current=head;
        for(int i=0;i<index;++i) 
            current= current->next;

        return current->val;
    }
 
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(size, val);       
    }
    
    void addAtIndex(int index, int val) {
        // Return if invalid index
        if (index>size || index < 0) 
            return;

        Node* current= head;
        Node* new_node = new Node(val);

        if (index == 0) {
            new_node->next = current;
            head = new_node;
        }else {
            for(int i=0;i<index-1;++i) 
                current= current->next;
            /* 
                current --> current->next
                            /
                        new_node
                        
                current    current->next
                      \      /
                        new_node           
            
            */            
            new_node->next = current->next;
            current->next = new_node;
        }
        size++;
    }
    
    void deleteAtIndex(int index) {
        // Return if invalid index
        if(index>=size || index < 0) 
            return;
        
        if (index == 0) {
            Node* nextNode = head->next;
            delete head;
            head = nextNode;            
        }else {
            Node* current= head;
            for(int i=0;i<index-1;++i) {
                current= current->next;
            }
            /* 
                current --> current->next --> current->next->next
                                                (next_node)
                        
                current --> DELETED --> current->next->next
                
                current --> next_node
            
            */  
            Node* nextNode = current->next->next;
            delete current->next;
            current->next = nextNode;
        }

            size--;
    }
    
    ~MyLinkedList()
    {
        Node *p = head;
        // Delete node at head while head is not null
        while (head!=nullptr)
        {
            head= head->next;
            delete p;
            p=head;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/next-greater-node-in-linked-list/">1019.next greater node in linked list</a></strong></summary>

```cpp
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>v;

        while(head){
            v.push_back(head->val);
            head=head->next;
        }

        int n=v.size()-1;
    
        for(int i=0;i<=n-1;i++){
            int x=v[i];
            for(int j=i+1;j<=n;j++){
                if(v[j]>x) {
                    v[i]=v[j];
                    break;
                }   
            }

            if(v[i]==x)
                v[i]=0;
        }
        
        v[n]=0;
        return v;
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/split-linked-list-in-parts/">725.split linked list in parts</a></strong></summary>

```cpp
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
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/linked-list-components/">817.linked list components</a></strong></summary>

```cpp
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
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/">109.convert sorted list to binary search tree</a></strong></summary>

```cpp
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* BST(vector<int>& v){
        if(v.size()==0) 
            return NULL;
        if(v.size()==1) 
            return new TreeNode(v[0]);

        int mid = v.size()/2;
        TreeNode* root= new TreeNode(v[mid]);

        vector<int> leftTree(v.begin(),v.begin()+mid);
        vector<int> rightTree(v.begin()+mid+1,v.end());

        root->left = BST(leftTree);
        root->right = BST(rightTree);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        ListNode* temp=head;
        vector<int> v;

        // Converting LinkedList into array
        while(temp){
            v.emplace_back(temp->val);
            temp=temp->next;
        }

        if(v.size()==0) 
            return NULL;
        if(v.size()==1) 
            return new TreeNode(v[0]);

        return BST(v);
    }
};
```
</details>

<details>
<summary><strong><a href = "https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/">1171.	remove zero sum consecutive nodes from linked list</a></strong></summary>

```cpp
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head)
            return NULL;

       vector<int> v;
       ListNode *temp=head;
       
       while(temp!=NULL){
           v.push_back(temp->val);
            temp=temp->next;
       }
        
       for(int i=0;i<v.size();i++){
           int sum=0;

           for(int j=i;j<v.size();j++){
               sum+=v[j];

               if(sum==0){
               v.erase(v.begin()+i,v.begin()+j+1);
               i--;
               break;
               }
           }
       }

       ListNode *ans=new ListNode(0);
       ListNode *res=ans;

       for(int i=0;i<v.size();i++){
           ListNode *newNode=new ListNode(v[i]);
           res->next=newNode;
           res=res->next;
        }

       return ans->next;
    }
};
```
</details>