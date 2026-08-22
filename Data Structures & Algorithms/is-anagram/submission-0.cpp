class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        unordered_map<char,int> sets;
        for(int i = 0;i < s.size();i++){
           sets[s[i]] = sets[s[i]] + 1;
        }
        for(int i = 0;i < t.size();i++){
            auto it = sets.find(t[i]);
            if(it != sets.end()){
                it -> second--;
                if((it -> second) < 0){
                    return false;
                }
            }
            else{
                return false;
            }
        }
        return true;
    }
};
