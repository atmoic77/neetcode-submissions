class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int x = nums.size();
        vector<int> prefix(x,0);
        vector<int> suffix(x,0);
        for(int i = 1;i < x;i++){
            prefix[i] = nums[i-1] + prefix[i-1];
        }
        for(int i = x-2;i >= 0;i--){
            suffix[i] = nums[i+1] + suffix[i+1];
        }
        for(int i = 0;i < x;i++){
            if(suffix[i] == prefix[i]){
                return i;
            }
        }
        return -1;
    }
};