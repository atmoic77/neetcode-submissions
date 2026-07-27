class Solution {
public:
    int calPoints(vector<string>& operations) {
       int s = operations.size();
       stack<int> st;
       int sum = 0;
       for(int i = 0;i < s;i++){

        if(isdigit(operations[i][0]) || operations[i][0] == '-'){
            st.push(stoi(operations[i]));
        }
        else if(operations[i] == "+"){
            int fispre = st.top();
            st.pop();
            int secpre = st.top();
            st.push(fispre);
            int newscore = fispre + secpre;
            st.push(newscore);
        }
        else if(operations[i] == "D"){
            st.push(2*st.top());
        }
        else{
            st.pop();
        }
       }
       int z = st.size();
       for(int i = 0;i < z;i++){
        sum += st.top();
        st.pop();
       }
       return sum;
    }
};