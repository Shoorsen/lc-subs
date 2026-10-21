class Solution {
public:
    const int ASCIIBase = 65;
    int characterReplacement(string s, int k) {
        int sz = s.size();
        // std::unordered_map<int, int> mp;
        int ans = 0;
        for (int ch {0}; ch < 26; ch++) {
            int letter = ch;
            letter += ASCIIBase;
            // mp[letter] = 0;
            int current = 0;
            int l = 0, r = 0;
            int remaining = k;
            while (r < s.size()) {
                if (s[r] != letter) {
                    if (remaining == 0) {
                        if (s[l] == letter) {
                            l++;
                        }
                        else if (s[l] != letter) {
                            l++;
                            remaining++;
                        }
                    } else {
                        remaining--;
                        r++;
                    }
                } else {
                    r++;
                }
                current = std::max(current, r-l);
                // mp[letter] = std::max(mp[letter], r-l);
            }
            ans = std::max(current, ans);
        }
        // int best = 0;
        // for (const auto& pair : mp) {
        //     if (pair.second > best) {
        //         best = pair.second;
        //     }
        // }
        return ans;
    }
};

