class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> map;
        int count = 0;
        map[0] = 1;
        int sum = 0;
        int n = nums.size();
        for(int i = 0;i < n;i++){
            sum += nums[i];
            if(map.contains(sum - k)){
            count += map[sum-k];
            }
            map[sum]++;
        }
        return count;
    }
};