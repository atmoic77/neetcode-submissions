class MyQueue {
public:

    stack<int> st_main;
    stack<int> st_sec;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(st_main.empty()){
            st_main.push(x);
        }
        else{
            while(!st_main.empty()){
                st_sec.push(st_main.top());
                st_main.pop();
            }
            st_main.push(x);
            while(!st_sec.empty()){
                st_main.push(st_sec.top());
                st_sec.pop();
            }
        }    
    }
    
    int pop() {
        int store = st_main.top();
        st_main.pop();
        return store;
    }
    
    int peek() {
        return st_main.top();
    }
    
    bool empty() {
        return st_main.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */