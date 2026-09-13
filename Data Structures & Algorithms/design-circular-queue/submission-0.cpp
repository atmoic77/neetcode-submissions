class MyCircularQueue {
private:
    struct Node {
        int val;
        Node* next;
        Node(int v) : val(v), next(nullptr) {}
    };
    
    Node* tail;   // points to the last inserted node
    int count;
    int capacity;

public:
    MyCircularQueue(int k) {
        tail = nullptr;
        count = 0;
        capacity = k;
    }
    
    bool enQueue(int value) {
        if (isFull()) return false;
        Node* newNode = new Node(value);
        if (tail == nullptr) {
            // first element: node points to itself
            newNode->next = newNode;
            tail = newNode;
        } else {
            newNode->next = tail->next; // new node points to head
            tail->next = newNode;       // old tail points to new node
            tail = newNode;             // update tail
        }
        count++;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty()) return false;
        Node* head = tail->next;
        if (head == tail) {
            // only one element
            tail = nullptr;
        } else {
            tail->next = head->next; // skip old head
        }
        delete head;
        count--;
        return true;
    }
    
    int Front() {
        if (isEmpty()) return -1;
        return tail->next->val;
    }
    
    int Rear() {
        if (isEmpty()) return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == capacity;
    }
    
    ~MyCircularQueue() {
        while (!isEmpty()) {
            deQueue();
        }
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