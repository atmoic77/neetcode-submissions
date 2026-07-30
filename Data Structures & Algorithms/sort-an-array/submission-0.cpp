class Solution {
public:

    void mergesort(vector<int>& nums,int left,int right){
        if(left >= right) return;
        else{
        int mid = (left + right)/2;
        mergesort(nums,left,mid);
        mergesort(nums,mid + 1,right);
        merge(nums,left,mid,right);
        }
    }
    void merge(vector<int>& nums,int left,int mid,int right){
        int i = left,j = mid + 1;
        vector<int> temp;
        while(i <= mid && j <= right){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]); i++;
            }
            else {
                temp.push_back(nums[j]); j++;
            }
        }
        while (i <= mid) temp.push_back(nums[i++]);
        while (j <= right)   temp.push_back(nums[j++]);
            for(int ind = 0;ind < temp.size();ind++){
                nums[ind + left] = temp[ind]; 
            }
        
    }
    vector<int> sortArray(vector<int>& nums) {
        int right = nums.size() - 1;
        mergesort(nums,0,right);
        return nums;
    }
};