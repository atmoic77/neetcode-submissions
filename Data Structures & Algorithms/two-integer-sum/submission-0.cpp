class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> maps;
        vector<int> result;
        int s = nums.size();
        for(int i = 0;i < s;i++){
            int compliment = (target - nums[i]);
            if(maps.contains(compliment)){
                if(i < maps[compliment]){
                    result.push_back(i);
                    result.push_back(maps[compliment]);
                    return result;
                }
                else{
                    result.push_back(maps[compliment]);
                    result.push_back(i);
                    return result;
                }
            }
            else{
                maps[nums[i]] = i;
            }
        }
        return {};
    }
};
