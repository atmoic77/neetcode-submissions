class Solution {
public:
    vector<int> dp;
    vector<int> countBits(int n) {
        dp.resize(n + 1,0);
        if(n < 0) return dp;
        if(n == 0) return dp;
        dp[0] = 0;
        dp[1] = 1;
        if(dp[n] != 0) return dp;
        for(int i = 2;i <= n;i++){
            dp[i] = dp[i >> 1] + (i&1);
        }
        return dp;
    }
};
