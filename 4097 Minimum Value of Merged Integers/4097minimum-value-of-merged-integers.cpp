class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            int cur = nums[i];
            int next = nums[i+1];
            int merged = std::stoi(std::to_string(cur) + std::to_string(next));
            ans = std::min(ans, merged);
            i++;
        }
        return ans;
    }
};