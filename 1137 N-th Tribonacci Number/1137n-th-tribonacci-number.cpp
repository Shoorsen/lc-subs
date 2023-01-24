class Solution {
public:
    int tribonacci(int n) {
        vector<int>dp(3, 0);
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3;i<=n;i++) 
            dp.push_back(dp[i-1] + dp[i-2] + dp[i-3]);
        return dp[n];
    }
};