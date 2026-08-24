class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0; int r = nums.size() - 1;
        int min = nums[0];
        while (l <= r) {
            std::cout << l << " " << r << std::endl;

            int mid = (l + r) / 2;

            int end_r = nums[r];
            int end_l = nums[l];
            if (end_r == target) {
                return r;
            }
            if (end_l == target) {
                return l;
            }

            int in_r_id = mid+1 <= nums.size()-1 ? mid+1 : 0;
            int in_l_id = mid-1 >= 0 ? mid-1 : nums.size()-1;

            int in_r = mid+1 <= nums.size()-1 ? nums[mid+1] : nums[0];
            int in_l = mid-1 >= 0 ? nums[mid-1] : nums[nums.size()-1];

            // if (in_r == target) {
            //     return in_r_id;
            // }
            // if (in_l == target) {
            //     return in_l_id;
            // }

            if (target == nums[mid]) {
                return mid;
            }

            if ((in_r < target && end_r < target)) {
                // r = mid - 1;
                if (end_r < in_r) {
                    l = mid+1;
                } else{
                    r = mid-1;
                }
            }
            else if (in_r > target && end_r > target) {
                if (in_r > end_r) {
                    l = mid + 1;
                }
                else {
                    r = mid-1;
                }
            }
            else if (in_r > target && end_r < target) {
                r = mid-1;
            }
            else {
                l = mid+1;
            }
        }
        return -1;

    }
};