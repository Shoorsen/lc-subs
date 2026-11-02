class Solution {
public:
    int sortPermutation(vector<int>& nums) {
        vector<int> opts;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i)  {
                opts.push_back(nums[i]);
            }
        }
        if (opts.empty()) {
            return 0;
        }
        int ans = opts[0];
        for (int i = 1; i < opts.size(); i++) {
            ans &= opts[i];
        }
        return ans;
    }
};