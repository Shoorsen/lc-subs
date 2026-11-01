class Solution {
public:
    int minMoves(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int count = 0;
        for (int i = nums.size()-1; i > 0; i--) {
            count += nums[i] - nums[0];
        }
        return count;

    }
};
// [1,1,5,7,8]
//[8,7,5,1,1]
//maxheap

