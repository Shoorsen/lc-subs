#include "bits/stdc++.h"
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int,pair<int,int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = pair<int,int>(13, i);
        }
        std::vector<int> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (mp[target - nums[i]].first == 13 && mp[target - nums[i]].second != i) {
                ans.push_back(i);
                ans.push_back(mp[target - nums[i]].second);
                return ans;
            }
        }
        return ans;
    }
};