class MyStack {
public:
    queue<int> q_main;
    queue<int> q_sup;
    MyStack() {
        
    }
    
    void push(int x) {
        if(q_main.empty()){
            q_main.push(x);
        }
        else{
            while(!q_main.empty()){
                q_sup.push(q_main.front());
                q_main.pop();
            }
            q_main.push(x);
            while(!q_sup.empty()){
              q_main.push(q_sup.front());
              q_sup.pop();  
            }
        }
    }
    
    int pop() {
        int store = top();
        q_main.pop();
        return store;
    }
    
    int top() {
        return q_main.front();
    }
    
    bool empty() {
        return q_main.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */