class MyCircularQueue {
int rear, front, length, *arr, size;
public:
    MyCircularQueue(int k) : size(k), rear(k - 1), front(0), length(0), arr(new int[k]) {}

    
    bool enQueue(int value) {
        if(isFull()) 
            return false;
        rear = (rear + 1) % size;
        arr[rear] = value;
        length++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        front = (front + 1) % size;
        --length;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return arr[front];
    }
    
    int Rear() {
        if(isEmpty()) 
            return -1;
        return arr[rear];
    }
    
    bool isEmpty() {
        return length == 0;
    }
    
    bool isFull() {
        return length == size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */