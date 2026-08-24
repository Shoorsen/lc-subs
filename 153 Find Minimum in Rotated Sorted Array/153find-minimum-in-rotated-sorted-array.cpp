class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0; int r = nums.size() - 1;
        int min = nums[0];
        while (l <= r) {
            int mid = (l + r) / 2;

            int end_r = nums[r];
            int end_l = nums[l];

            int in_r = mid+1 <= nums.size()-1 ? nums[mid+1] : nums[0];
            int in_l = mid-1 >= 0 ? nums[mid-1] : nums[nums.size()-1];

            if (in_r >= nums[mid] && in_l >= nums[mid]) {
                return nums[mid];
            }

            if ((in_r > nums[mid] && end_r > nums[mid])) {
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return -1;
    }
};