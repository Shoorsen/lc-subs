class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int product = 1;
        int n = nums.size();
        vector<int> ans(n, 1);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                continue;
            } else if (i == 1) {
                ans[i] *= nums[i-1];
            } else {
                ans[i] *= ans[i-1] * nums[i-1];
            }
        }
        for (int i = n-1; i >= 0; i--) {
            if (i == n-1) {
                product = nums[i];
            } else {
                ans[i] *= product;
                product *= nums[i];
            }
        }
        return ans;
    }
};
