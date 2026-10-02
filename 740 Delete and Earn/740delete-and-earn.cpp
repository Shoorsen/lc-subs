class Solution {
public:

    int deleteAndEarn(vector<int>& nums) {
        // int maxNum = *std::max_element(nums.begin(), nums.end());
        std::map<int, int> mp;
        for (int num : nums) {
            mp[num] += num;
        }

        int dp[20002];
        std::memset(dp, 0, sizeof(dp));
        int lastNum = std::prev(mp.end())->first;
        dp[lastNum] = mp[lastNum];

        for (int num = lastNum; num >= 0; num--) {
            // int num = pair->first;
            if (dp[num] > 0) {
                continue;
            }
            dp[num] = std::max(dp[num+1], dp[num+2] + mp[num]);
        }

        return dp[0];

    }
};

