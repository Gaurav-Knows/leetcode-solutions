class MyCircularQueue {
public:

    vector<int> q;
    int front;
    int rear;
    int size;
    int capacity;

    MyCircularQueue(int k) {
        capacity = k;
        q.resize(k);
        front = -1;
        rear = -1;
        size = 0;
        
    }
    
    bool enQueue(int value) {
        if(size==capacity){
            return false;
        }

        if(size==0){
            front=0;
            rear=0;
            q[rear] = value;
            
            size++;
            return true;
        }

        rear=(rear+1)%capacity;
        q[rear] = value;
        size++;

        return true;
    }
    
    bool deQueue() {
        if(size==0){
            return false;
        }

        if(size == 1) {
        front = -1;
        rear = -1;
        size = 0;
        return true;
        }

        front=(front+1)%capacity;
        size--;

        return true;
        
    }
    
    int Front() {

    if(size == 0)
        return -1;

    return q[front];
    }

    int Rear() {
        
    if(size == 0)
        return -1;

    return q[rear];
    }
    
    bool isEmpty() {
        if(size==0){
            return true;
        }

        return false;
        
    }
    
    bool isFull() {
        if(size==capacity){
            return true;
        }
        return false;
        
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