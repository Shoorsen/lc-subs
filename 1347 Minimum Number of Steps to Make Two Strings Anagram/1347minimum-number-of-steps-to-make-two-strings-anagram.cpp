class Solution {
public:
    int minSteps(string s, string t) {
        std::unordered_map<char, int> sMap;
        std::unordered_map<char, int> tMap;
        for (const auto& ch : s) {
            sMap[ch]++;
        }
        for (const auto& ch : t) {
            tMap[ch]++;
        }
        int ans = 0;
        for (const auto& pair : sMap) {
            char letter = pair.first;
            int count = pair.second;
            if (tMap[letter] < count) {
                ans += count - tMap[letter];
            }
        }
        return ans;
    }
};