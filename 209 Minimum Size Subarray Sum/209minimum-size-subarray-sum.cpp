class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0; int right = 0;
        int sum = nums[0];
        int length = nums.size() + 1;
        bool checked = false;
        while (right < nums.size()) {
            
            while (sum >= target) {
                if (right - left + 1 < length) {
                    length = right - left + 1;
                }
                sum -= nums[left];
                left++;
            }
            right++;
            if (right < nums.size()) {
                sum += nums[right];
            }

        }
        if (length > nums.size()) {
            return 0;
        }
        return length;
    }
};