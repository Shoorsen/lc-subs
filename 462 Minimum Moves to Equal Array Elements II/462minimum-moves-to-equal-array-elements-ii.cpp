class Solution {
public:
    int minMoves2(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int med = nums[nums.size()/2];
        int ans = 0;
        if (nums.size()%2==0) {
            int medU = med;
            med--;
            for (int i = 0; i <= nums.size()/2-1; i++) {
                ans += med - nums[i];
            }
            for (int i = nums.size()/2; i < nums.size(); i++) {
                ans += nums[i] - medU;
            }
            ans += (medU-med) * nums.size()/2;
        } else{
            int med = nums[nums.size()/2];
            for (int i  = 0; i < nums.size(); i++) {
                if (i < nums.size()/2) {
                    ans += nums[nums.size()/2] - nums[i];
                } else {
                    ans += nums[i] - nums[nums.size()/2];
                }
            }
        }
        return ans;
    }
};

// [2,2,9,9]

// [1,2,9.10]

// 7+3+6