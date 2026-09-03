class Solution {
public:

    string encode(vector<string>& strs) {
        string encode = "";
        for(string &s : strs){
            encode += to_string(s.size()) + "#" + s;
        }
        return encode;
    }

    vector<string> decode(string s) {
        vector<string> decode;
        int i = 0;
        while(i < s.size()){
            int j = i;
            while(s[j] != '#') j++;
            int len = stoi(s.substr(i, j - i));
            string word = s.substr(j+1,len);
            decode.push_back(word);
            i = j + 1 + len;
        } 
        return decode;
    }
};
