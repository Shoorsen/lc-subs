class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        map<int,int> mp;//nums as a map
        map<int,bool> seen;
        for (int i = 0; i <nums.size();i++) {
            mp[nums[i]] = 1;
            seen[nums[i]] = false;
        }
        int m = -1000000009;
        for (int i = 0; i < nums.size(); i++) {
            int curr = 1;
            if (seen[nums[i]] == true) {
                continue;
            }
            seen[nums[i]] = true;
            for (int j = nums[i]+1; j <= 1000000009; j++) {
                seen[j] = true;
                if (mp[j] == 1) {
                    curr++;
                } else {
                    break;
                }
            }
            for (int j = nums[i]-1; j >= -1000000009; j--) {
                seen[j] = true;
                if (mp[j] == 1) {
                    curr++;
                } else {
                    break;
                }
            }
            m = max(m, curr);
        }
        return m;
    }
};
// 0[4]
// 1[4]
// 2[3]
// 3[4]
// 4[4]
// 5[4]
// 6[4]
// 7[3]
// 8[3]