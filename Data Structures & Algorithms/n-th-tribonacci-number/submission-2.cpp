class Solution {
public:
    int tribonacci(int n) {
       int dp1 = 0;
       int dp2 = 1;
       int dp3 = 1;
       if(n == 0) return 0;
       for(int i = 3;i <= n;i++){
        int current = dp1 + dp2 + dp3;
        dp1 = dp2;
        dp2 = dp3;
        dp3 = current;
       }  
       return dp3;
    }
};