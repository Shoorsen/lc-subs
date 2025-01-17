class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // n log n
        // vector<int> ans;
        // map<int,int> mp; 
        // int n = nums.size();
        // for (int i = 0; i < n; i++) {
        //     mp[nums[i]]++;
        //     if (mp[nums[i]] == 1) {
        //         ans.push_back(nums[i]);
        //     }
        // }
        // sort(ans.begin(), ans.end(), [&mp](int a, int b) { return mp[a] > mp[b];});
        // ans.erase(ans.begin() + k, ans.end());
        // return ans;
        //o(n), use frequencies as counts in map my solution
        // vector<int> ans;
        // map<int, int> count_map;
        // int n = nums.size();
        // int size = 0;
        // for (int i = 0; i < n; i++) {
        //     count_map[nums[i]]++;
        //     if (count_map[nums[i]] > size) {
        //         size++;
        //     }
        // }
        // // vector<vector<int>> mp(size);
        // map<int, vector<int>> mp;
        // for (const auto& pair : count_map) {
        //     mp[pair.second].push_back(pair.first);
        // }
        // for (int i = n; i >= 1; i--) {
        //     if (k == 0) {
        //         return ans;
        //     }
        //     if (mp[i].empty()) {
        //         continue;
        //     }
        //     else {
        //         for (int x : mp[i]) {
        //             ans.push_back(x);
        //             k--;
        //             if (k == 0) { return ans; }
        //         }
        //     }
        // }
        // return ans;


        //neetcode solution
        map<int,int> count;
        vector<vector<int>> freq(nums.size()+1);
        for (auto n : nums) {
            count[n]++;
        }
        for (const auto& pair : count) {
            freq[pair.second].push_back(pair.first);
        }
        vector<int> ans;
        for (int i = nums.size(); i > 0; i--) {
            for (auto n : freq[i]) {
                ans.push_back(n);
                if (ans.size() == k) {
                    return ans;
                }
            }
        }
        return ans;
    }
};