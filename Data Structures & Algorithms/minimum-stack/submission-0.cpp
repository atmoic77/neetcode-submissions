class MinStack {
public:
    vector<int> st;
    vector<int> min_st;
    MinStack() {
    }
    
    void push(int val) {
        if(st.empty()){
            st.push_back(val);
            min_st.push_back(val);
        }
        else{
            if(min_st.back() > val){
                min_st.push_back(val);
            }
            else{
                int store = min_st.back();
                min_st.push_back(store); 
            }
            st.push_back(val);
        }
    }
    
    void pop() {
        min_st.pop_back();
        st.pop_back();
    }
    
    int top() {
        return st.back();
    }
    
    int getMin() {
        return min_st.back();
    }
};
