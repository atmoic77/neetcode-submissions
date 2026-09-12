class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int s = nums.size();
        unordered_map<int,int> maps;
        for(int i = 0;i < s;i++){
            maps[nums[i]]++;
        }
        int ele = 0;
        for(auto it : maps){
            ele = it.first;
            int count = it.second;
            if(count == 1) return ele;
        }
        return ele; 
    }
};
