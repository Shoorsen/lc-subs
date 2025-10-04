class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> set;
        for (int i = 0; i<nums.size(); i++) {
            int left = i + 1; int right = nums.size() - 1;
            // int target = -1 * nums[i];//2
            //[-4, 2, -1, 0, 1, 2]
            while (left < right) {
                int sum = nums[left] + nums[right] + nums[i];
                if (sum == 0) {
                    // int mini = min(min(nums[left], nums[right]), min(nums[left], nums[i]));
                    // int maxi = max(max(nums[left], nums[right]), max(nums[left], nums[i]));
                    // vector<int> v = {mini, -(mini + maxi), maxi};
                    vector<int> v = {nums[i], nums[left], nums[right]};

                    if (!set.contains(v)) {
                        set.insert(v);
                        ans.push_back(v);
                    }
                    left++; right--;
                    }
                    else if (sum > 0) {
                        right--;
                    } else {
                        left++;
                    }
                }
            }
        return ans;
    }
};