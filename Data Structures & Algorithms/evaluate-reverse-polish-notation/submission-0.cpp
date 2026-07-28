class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int z = tokens.size();
        stack<int> st;
        int res;
        for(int i = 0;i < z;i++){
             if(isdigit(tokens[i][0]) || (tokens[i][0] == '-' && tokens[i].length() > 1)){
            st.push(stoi(tokens[i]));
        }
            else{
                int ope1 = st.top();
                st.pop();
                int ope2 = st.top();
                st.pop();
                if(tokens[i] == "+"){
                    res = ope1 + ope2;
                }
                else if(tokens[i] == "*"){
                    res = ope1 * ope2;
                }
                else if(tokens[i] == "-"){
                    res = ope2 - ope1;
                }
                else{
                    res = ope2 / ope1;
                }
                st.push(res);
            }
        }
        return st.top();
    }
};
