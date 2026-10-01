class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) {
            return 0;
        }
        std::unordered_map<char, int> last_seen_at;
        int l = 0;
        int substr = 0;
        int ans = 1;
        for (int r = 0; r < s.size(); r++) {
            if (last_seen_at.contains(s[r]) && last_seen_at[s[r]] >= l) {
                l = last_seen_at[s[r]] + 1;
                substr = r-l+1;
            } else {
                substr++;
            }
            ans = std::max(ans, substr);
            last_seen_at[s[r]] = r;
        }
        return ans;
    }
};