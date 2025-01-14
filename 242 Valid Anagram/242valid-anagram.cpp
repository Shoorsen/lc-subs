class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> smap;
        map<char,int> tmap;
        if (s.size() != t.size()) {
            return false;
        }
        for (int i = 0; i < s.size(); i++) {
            smap[s[i]]++;
            tmap[t[i]]++;
        }
        for (const auto& pair : smap) {
            if (tmap[pair.first] != pair.second) {
                return false;
            }
        }
        return true;
    }
};