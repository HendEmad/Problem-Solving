# LeetCode OJ - Interviews Questions 1 <br> Linked List `15 problems`

## reverse linked list
Problem Link: https://leetcode.com/problems/reverse-linked-list

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution(object):
    def reverseList(self, head):
        prev = None
        cur = head
        while cur:
            next_node = cur.next
            cur.next = prev
            prev = cur
            cur = next_node
        return prev
```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode prev = null;
        ListNode cur = head;
        while (cur != null) {
            ListNode next_node = cur.next;
            cur.next = prev;
            prev = cur;
            cur = next_node;
        }
        return prev;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* cur = head;

    while(cur) {
        struct ListNode* next_node = cur -> next;
        cur ->next = prev;
        prev = cur;
        cur = next_node;
    }    
    return prev;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* cur = head;
        while (cur) {
            ListNode* next = cur ->next;
            cur ->next = prev;
            prev = cur;
            cur = next;
        }        
        return prev;
    }
};
```

</details>
<br>

## swap nodes in pairs
Problem Link: https://leetcode.com/problems/swap-nodes-in-pairs

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution(object):
    def swapPairs(self, head):
        temp = ListNode(0)
        temp.next = head
        prev = temp

        while prev.next and prev.next.next:
            first = prev.next
            sec = prev.next.next
            prev.next = sec
            first.next = sec.next
            sec.next = first
            prev = first
        
        return temp.next
```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public ListNode swapPairs(ListNode head) {
        ListNode temp = new ListNode(0);
        temp.next = head;
        ListNode prev = temp;

        while (prev.next!= null && prev.next.next != null) {
            ListNode first = prev.next;
            ListNode sec = prev.next.next;
            prev.next = sec;
            first.next = sec.next;
            sec.next = first;
            prev = first;
        }   
        return temp.next;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
struct ListNode* swapPairs(struct ListNode* head) {
    struct ListNode temp;
    temp.next = head;
    struct ListNode* prev = &temp;

    while(prev ->next && prev ->next ->next) {
        struct ListNode* first = prev ->next;
        struct ListNode* sec = prev ->next ->next;
        prev ->next = sec;
        first ->next = sec ->next;
        sec ->next = first;
        prev = first;
    }
    return temp.next;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode temp(0);
        temp.next = head;
        ListNode* prev = &temp;

        while(prev ->next && prev ->next ->next) {
            ListNode* first = prev ->next;
            ListNode* sec = prev ->next ->next;
            prev ->next = sec;
            first ->next = sec ->next;
            sec ->next = first;
            prev = first;
        }        
        return temp.next;
    }
};
```

</details>
<br>

## linked list cycle ii
Problem Link: https://leetcode.com/problems/linked-list-cycle-ii

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        ptr_1node = ptr_2nodes = head
        while ptr_2nodes and ptr_2nodes.next:
            ptr_1node = ptr_1node.next
            ptr_2nodes = ptr_2nodes.next.next
            if ptr_1node == ptr_2nodes:
                ptr_1node = head
                while ptr_1node != ptr_2nodes:
                    ptr_1node = ptr_1node.next
                    ptr_2nodes = ptr_2nodes.next
                return ptr_1node
        return None
```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
public class Solution {
    public ListNode detectCycle(ListNode head) {
        ListNode ptr_1node = head, ptr_2nodes = head;
        while (ptr_2nodes != null && ptr_2nodes.next != null) {
            ptr_1node = ptr_1node.next;
            ptr_2nodes = ptr_2nodes.next.next;
            if(ptr_1node == ptr_2nodes) {
                ptr_1node = head;
                while (ptr_1node != ptr_2nodes) {
                    ptr_1node = ptr_1node.next;
                    ptr_2nodes = ptr_2nodes.next;
                }
                return ptr_1node;
            }
        }
        return null;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *ptr_1node = head, *ptr_2nodes = head;
    while (ptr_2nodes && ptr_2nodes -> next) {
        ptr_1node = ptr_1node -> next;
        ptr_2nodes = ptr_2nodes -> next -> next;
        if (ptr_1node == ptr_2nodes) {
            ptr_1node = head;
            while (ptr_1node != ptr_2nodes) {
                ptr_1node = ptr_1node -> next;
                ptr_2nodes = ptr_2nodes -> next;
            }
            return ptr_1node;
        }
    }    
    return NULL;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *ptr_1node = head, *ptr_2nodes = head;
        while (ptr_2nodes && ptr_2nodes -> next) {
            ptr_1node = ptr_1node -> next;
            ptr_2nodes = ptr_2nodes -> next -> next;
            if (ptr_1node == ptr_2nodes) {
                ptr_1node = head;
                while (ptr_1node != ptr_2nodes) {
                    ptr_1node = ptr_1node -> next;
                    ptr_2nodes = ptr_2nodes -> next;
                }
                return ptr_1node;
            }
        }      
        return nullptr;
    }
};
```

</details>
<br>

## sort list
Problem Link: https://leetcode.com/problems/sort-list

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution:
    def get_mid(self, head):
        if not head:
            return None
        cur1, cur2 = head, head.next
        while cur2 and cur2.next:
            cur1 = cur1.next
            cur2 = cur2.next.next
        mid = cur1.next
        cur1.next = None
        return mid

    def merge(self, left_list, right_list):
        temp = ListNode(0)
        cur = temp

        while left_list and right_list:
            if left_list.val < right_list.val:
                cur.next = left_list
                left_list = left_list.next
            else:
                cur.next = right_list
                right_list = right_list.next
            cur = cur.next
        
        cur.next = left_list if left_list else right_list
        return temp.next

    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head or not head.next:
            return head
        
        mid = self.get_mid(head)
        left = self.sortList(head)
        right = self.sortList(mid)

        return self.merge(left, right)
```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public ListNode get_mid(ListNode head) {
        if(head == null)
            return null;
        
        ListNode cur1 = head;
        ListNode cur2 = head.next;
        while (cur2 != null && cur2.next != null) {
            cur1 = cur1.next;
            cur2 = cur2.next.next;
        }
        ListNode mid = cur1.next;
        cur1.next = null;
        return mid;
    }

    public ListNode merge(ListNode left_list, ListNode right_list) {
        ListNode temp = new ListNode(0);
        ListNode cur = temp;

        while(left_list != null && right_list != null) {
            if (left_list.val < right_list.val) {
                cur.next = left_list;
                left_list = left_list.next;
            } else {
                cur.next = right_list;
                right_list = right_list.next;
            }
            cur = cur.next;
        }
        cur.next = left_list != null ? left_list : right_list;
        return temp.next;
    }

    public ListNode sortList(ListNode head) {
        if(head == null || head.next == null) 
            return head;

        ListNode mid = get_mid(head);
        ListNode left = sortList(head);
        ListNode right = sortList(mid);

        return merge(left, right);
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
struct ListNode* get_mid(struct ListNode* head) {
    if (head == NULL)
        return NULL;
    
    struct ListNode* cur1 = head;
    struct ListNode* cur2 = head -> next;
    while(cur2 != NULL && cur2 -> next != NULL) {
        cur1 = cur1 -> next;
        cur2 = cur2 -> next -> next;
    }
    struct ListNode* mid = cur1 -> next;
    cur1 -> next = NULL;
    return mid;
}

struct ListNode* merge(struct ListNode* left_list, struct ListNode* right_list) {
    struct ListNode temp;
    struct ListNode* cur = &temp;

    while(left_list != NULL && right_list != NULL) {
        if(left_list -> val < right_list -> val) {
            cur -> next = left_list;
            left_list = left_list -> next;
        }
        else {
            cur -> next = right_list;
            right_list = right_list -> next;
        }
        cur = cur -> next;
    }
    cur -> next = left_list != NULL ? left_list : right_list;
    return temp.next;
}

struct ListNode* sortList(struct ListNode* head) {
    if(head == NULL || head -> next == NULL)
        return head;

    struct ListNode* mid = get_mid(head);
    struct ListNode* left = sortList(head);
    struct ListNode* right = sortList(mid);
    return merge(left, right);
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head -> next == nullptr)
            return head;

        ListNode* mid = get_mid(head);
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        return merge(left, right);
    }

private:
    ListNode* get_mid(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* cur1 = head;
        ListNode* cur2 = head -> next;
        while(cur2 != nullptr && cur2 -> next != nullptr) {
            cur1 = cur1 -> next;
            cur2 = cur2 -> next -> next;
        }
        ListNode* mid = cur1 -> next;
        cur1 -> next = nullptr;
        return mid;
    }

    ListNode* merge(ListNode* left_list, ListNode* right_list) {
        ListNode temp(0);
        ListNode* cur = &temp;

        while(left_list != nullptr && right_list != nullptr) {
            if(left_list -> val < right_list -> val) {
                cur -> next = left_list;
                left_list = left_list -> next;
            }
            else {
                cur -> next = right_list;
                right_list = right_list -> next;
            }
            cur = cur -> next;
        }
        cur -> next = left_list != nullptr ? left_list : right_list;
        return temp.next;
    }
};
```

</details>
<br>

## merge k sorted lists
Problem Link: https://leetcode.com/problems/merge-k-sorted-lists

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution(object):
    def mergeKLists(self, lists):
        min_heap = []
        for i, list in enumerate(lists):
            if list:
                heapq.heappush(min_heap, (list.val, i, list))
        
        temp = ListNode(0)
        cur = temp

        while min_heap:
            val, i, node = heapq.heappop(min_heap)
            cur.next = node
            cur = cur.next
            if node.next:
                heapq.heappush(min_heap, (node.next.val, i, node.next))
        
        return temp.next
```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists == null || lists.length == 0) return null;
        PriorityQueue<ListNode> min_heap = new PriorityQueue<>(
                            Comparator.comparingInt(a -> a.val));

        for(ListNode list : lists)a
            if(list != null)
                min_heap.offer(list);

        ListNode temp = new ListNode(0);
        ListNode cur = temp;

        while(!min_heap.isEmpty()) {
            ListNode node = min_heap.poll();
            cur.next = node;
            cur = cur.next;
            if(node.next != null) 
                min_heap.offer(node.next);
        }

        return temp.next;        
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
typedef struct {
    struct ListNode **heap;
    int size;
    int capacity;
} MinHeap;

MinHeap* create(int capacity) {
    MinHeap* min_heap = (MinHeap*)malloc(sizeof(MinHeap));
    min_heap -> heap = (struct ListNode**)malloc(capacity * sizeof(struct ListNode*));
    min_heap -> size = 0;
    min_heap -> capacity = capacity;
    return min_heap;
}

void swap(struct ListNode **a, struct ListNode **b) {
    struct ListNode *temp = *a;
    *a = *b;
    *b = temp;
}

// maintain heap property when inserting a new node
void heapify_insertion(MinHeap *min_heap, int idx) {
    while (idx > 0) {
        int parent = (idx - 1) / 2;
        if (min_heap -> heap[parent] -> val <= min_heap -> heap[idx] -> val) break;
        swap(&min_heap -> heap[parent], &min_heap -> heap[idx]);
        idx = parent;
    }
}

// maintain heap property when extracting the node 
void heapify_extraction(MinHeap *min_heap, int idx) {
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    int smallest = idx;

    if(left < min_heap -> size && min_heap -> heap[left] -> val < min_heap -> heap[smallest] -> val)
        smallest = left;

    if(right < min_heap -> size && min_heap -> heap[right] -> val < min_heap -> heap[smallest] -> val)
        smallest = right;

    if(smallest != idx) {
        swap(&min_heap -> heap[idx], &min_heap -> heap[smallest]);
        heapify_extraction(min_heap, smallest);
    }
}

void insert(MinHeap *min_heap, struct ListNode* node) {
    if(min_heap -> size == min_heap -> capacity)
        return;
    
    min_heap -> heap[min_heap -> size] = node;
    heapify_insertion(min_heap, min_heap -> size);
    min_heap -> size++;
}

struct ListNode *extract_min(MinHeap* min_heap) {
    if(min_heap -> size == 0) return NULL;

    struct ListNode* min_node = min_heap -> heap[0];
    min_heap -> heap[0] = min_heap -> heap[min_heap -> size - 1];
    min_heap -> size--;
    heapify_extraction(min_heap, 0);
    return min_node; 
}

int is_empty(MinHeap *min_heap) {
    return min_heap -> size == 0;
}

struct ListNode* mergeKLists(struct ListNode** lists, int size) {
    if (size == 0) return NULL;
    int total_nodes = 0;
    for(int i = 0; i < size; i++) {
        struct ListNode* cur = lists[i];
        while(cur != NULL) {
            total_nodes++;
            cur = cur -> next;
        }
    }
    if(total_nodes == 0)
        return NULL;

    MinHeap *min_heap = create(total_nodes);
    for(int i = 0; i < size; i++) 
        if (lists[i] != NULL)
            insert(min_heap, lists[i]);

    struct ListNode temp;
    struct ListNode* cur = &temp;
    temp.next = NULL;

    while(!is_empty(min_heap)) {
        struct ListNode* min_node = extract_min(min_heap);
        cur -> next = min_node;
        cur = cur -> next;
        if(min_node -> next != NULL) 
            insert(min_heap, min_node -> next);
    }

    struct ListNode* res = temp.next;
    free(min_heap -> heap);
    free(min_heap);
    return res;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto comparator = [](ListNode *a, ListNode *b) {
            return a -> val > b -> val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comparator)>min_heap(comparator);
        for(ListNode* list : lists)
            if (list)
                min_heap.push(list);

        ListNode res(0);
        ListNode* cur = &res;

        while(!min_heap.empty()) {
            ListNode* node = min_heap.top();
            min_heap.pop();
            cur -> next = node;
            cur = cur -> next;
            if(node -> next)
                min_heap.push(node -> next);
        }
        return res.next;
    }
};
```

</details>
<br>

## linked list cycle
Problem Link: https://leetcode.com/problems/linked-list-cycle

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        if not head or not head.next:
            return False

        cur1 = head
        cur2 = head.next
        while cur1 != cur2:
            if not cur2 or not cur2.next:
                return False
            cur1 = cur1.next
            cur2 = cur2.next.next
        
        return True
```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
public class Solution {
    public boolean hasCycle(ListNode head) {
        if (head == null || head.next == null)
            return false;

        ListNode cur1 = head;
        ListNode cur2 = head.next;
        while (cur1 != cur2) {
            if (cur2 == null || cur2.next == null) 
                return false;

            cur1 = cur1.next;
            cur2 = cur2.next.next;
        }   
        return true;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
bool hasCycle(struct ListNode *head) {
    if (head == NULL || head -> next = NULL)
        return false;

    struct ListNode* cur1 = head;
    struct ListNode* cur2 = head -> next;

    while(cur1 != cur2) {
        if(cur2 == NULL || cur2 -> next == NULL)
            return false;
        cur1 = cur1 ->next;
        cur2 = cur2 ->next ->next;
    }    
    return true;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head -> next == nullptr) 
            return false;

        ListNode *cur1 = head;
        ListNode *cur2 = head -> next;
        while(cur1 != cur2) {
            if (cur2 == nullptr || cur2 -> next == nullptr) 
                return false;
            
            cur1 = cur1 -> next;
            cur2 = cur2 -> next -> next;
        }        
        return true;
    }
};
```

</details>
<br>

## merge two sorted lists
Problem Link: https://leetcode.com/problems/merge-two-sorted-lists

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        res = ListNode()
        cur = res

        while list1 and list2:
            if list1.val <= list2.val:
                cur.next = list1
                list1 = list1.next
            else:
                cur.next = list2
                list2 = list2.next
            cur = cur.next
        
        cur.next = list1 if list1 else list2
        return res.next
```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode res = new ListNode();
        ListNode cur = res;

        while (list1 != null && list2 != null) {
            if (list1.val <= list2.val) {
                cur.next = list1;
                list1 = list1.next;
            } else {
                cur.next = list2;
                list2 = list2.next;
            }
            cur = cur.next;
        }

        cur.next = list1 != null ? list1 : list2;
        return res.next;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode res;
    struct ListNode* cur = &res;
    res.next = NULL;

    while (list1 && list2) {
        if (list1 -> val <= list2 -> val) {
            cur -> next = list1;
            list1 = list1 -> next;
        } else {
            cur -> next = list2;
            list2 = list2 -> next;
        }
        cur = cur -> next;
    }
    cur -> next = list1 ? list1 : list2;
    return res.next;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode res;
        ListNode* cur = &res;

        while (list1 && list2) {
            if (list1 -> val <= list2 -> val) {
                cur -> next = list1;
                list1 = list1 -> next;
            } else {
                cur -> next = list2;
                list2 = list2 -> next;
            }
            cur = cur -> next;
        }
        cur -> next = list1 ? list1 : list2;
        return res.next;
    }
};
```

</details>
<br>

## reverse linked list ii
Problem Link: https://leetcode.com/problems/reverse-linked-list-ii

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python
class Solution:
    def reverseBetween(self, head: Optional[ListNode], left: int, right: int) -> Optional[ListNode]:
        if not head or left == right:
            return head
        
        res = ListNode(0)
        res.next = head
        prev = res

        for _ in range(left - 1):
            prev = prev.next
        
        s = prev.next
        n = s.next

        for _ in range(right - left):
            s.next = n.next
            n.next = prev.next
            prev.next = n
            n = s.next
        
        return res.next
```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java
class Solution {
    public ListNode reverseBetween(ListNode head, int left, int right) {
        if (head == null || left == right) 
            return head;

        ListNode res = new ListNode(0);
        res.next = head;
        ListNode prev = res;

        for(int i = 0; i < left - 1; i++)
            prev = prev.next;

        ListNode s = prev.next;
        ListNode n = s.next;

        for(int i = 0; i < right - left; i++) {
            s.next = n.next;
            n.next = prev.next;
            prev.next = n;
            n = s.next;
        }
        return res.next;
    }
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c
struct ListNode* reverseBetween(struct ListNode* head, int left, int right) {
    if (head == NULL || left == right) 
        return head;
    
    struct ListNode res;
    res.next = head;
    struct ListNode* prev = &res;

    for(int i = 0; i < left - 1; i++) 
        prev = prev -> next;

    struct ListNode* s = prev -> next;
    struct ListNode* n = s -> next;

    for(int i = 0; i < right - left; i++) {
        s -> next = n -> next;
        n -> next = prev -> next;
        prev -> next = n;
        n = s -> next;
    }
    return res.next;
}
```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == nullptr || left == right)
            return head;

        ListNode res(0);
        res.next = head;
        ListNode* prev = &res;

        for(int i = 0; i < left - 1; i++)
            prev = prev -> next;

        ListNode* s = prev -> next;
        ListNode* n = s -> next;

        for (int i = 0; i < right - left; i++) {
            s -> next = n -> next;
            n -> next = prev -> next;
            prev -> next = n;
            n = s -> next;
        }
        return res.next;
    }
};
```

</details>
<br>

## remove nth node from end of list
Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<br>

## rotate list
Problem Link: https://leetcode.com/problems/rotate-list

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<br>

## middle of the linked list
Problem Link: https://leetcode.com/problems/middle-of-the-linked-list

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<br>

## remove linked list elements
Problem Link: https://leetcode.com/problems/remove-linked-list-elements

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<br>

## remove duplicates from sorted list
<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<br>

## reorder list
Problem Link: https://leetcode.com/problems/reorder-list

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<br>

## odd even linked list
Problem Link: https://leetcode.com/problems/odd-even-linked-list

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/python.png"></img></picture>
<details>
    <summary>Python Solution</summary>

```python

```
</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/java.png"></img></picture>
<details>
    <summary>Java Solution</summary>

```java

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/c.png"></img></picture>
<details>
    <summary>C Solution</summary>

```c

```

</details>

<picture><img align="right" width="40" height="38" src="https://github.com/cs-MohamedAyman/cs-MohamedAyman/blob/master/logos/cpp.png"></img></picture>
<details>
    <summary>C++ Solution</summary>

```cpp

```

</details>
<br>
