class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> maps;
        int s = nums.size();
        for(int i = 0;i < s;i++){
            if(maps.contains(nums[i])){
                return true;
            }
            else{
                maps.insert(nums[i]);
            }
        }
        return false;
    }
};