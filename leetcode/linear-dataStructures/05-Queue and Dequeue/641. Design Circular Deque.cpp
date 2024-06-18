class MyCircularDeque {
public:
    int n;
    class DLL {
    public:
        int val;
        DLL* next;
        DLL* prev;
        DLL (int n) {
            val = n;
        }
    };

    DLL* head = new DLL(-1);
    DLL* tail = new DLL(-1);
    DLL* lastAdded = tail;
    int curSize = 0;

    MyCircularDeque(int k) {
        n = k;
        head -> next = tail;
        tail -> prev = head;
    }
    
    bool insertFront(int value) {
        if (curSize == n)
            return false;

        curSize++;
        DLL* temp = new DLL(value);
        temp -> next = head -> next;
        head -> next -> prev = temp;
        head -> next = temp;
        temp -> prev = head;
        return true;
    }


    
    bool insertLast(int value) {
        if (curSize == n)
            return false;
        curSize++;
        DLL* temp = new DLL(value);
        temp -> next = tail;
        tail -> prev -> next = temp;
        tail -> prev = temp;
        temp -> prev = tail -> prev;
        return true;
    }
    
    bool deleteFront() {
        if (curSize == 0)
            return false;
        DLL* temp = head -> next;
        head -> next -> prev = head;
        head -> next = temp -> next;
        temp -> next = temp -> prev = NULL;
        curSize--;
        return true;
    }
    
    bool deleteLast() {
        if (curSize == 0)
            return false;
        DLL* temp = tail -> prev;
        tail -> prev = temp -> prev;
        temp -> prev -> next = tail;
        temp -> prev = temp -> next = NULL;
        curSize--;
        return true;
    }
    
    int getFront() {
        if (head -> next -> val == -1)
            return -1;
        return head -> next -> val;
    }
    
    int getRear() {
        if (tail -> prev -> val == -1)
            return -1;
        return tail -> prev -> val;
    }
    
    bool isEmpty() {
        return (curSize == 0);
    }
    
    bool isFull() {
        return (curSize == n);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */