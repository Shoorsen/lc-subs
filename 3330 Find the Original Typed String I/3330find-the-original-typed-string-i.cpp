class Solution {
public:
    int possibleStringCount(string word) {
        char prev;
        int ans = 1;
        for (int i = 0; i < word.size(); i++) {
            char cur = word[i];
            if (i == 0) {
                prev = word[i];
                continue;
            }
            if (cur == prev) {
                ans++;
            }
            prev = cur;
        }
        return ans;
    }
};

