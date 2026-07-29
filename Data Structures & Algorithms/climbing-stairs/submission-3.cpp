class Solution {
public:
    int memo[46] = {0};
    int climbStairs(int n) {
        if(n < 0) return 0;
        else if(n == 0 || n == 1){
            return 1;
        }
        if(memo[n] != 0) return memo[n];
        else{
            return memo[n] = climbStairs(n-1) + climbStairs(n-2);
        }
    }
};