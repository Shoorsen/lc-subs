class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char, int> mag;
        map<char, int> nott;
        for (int i = 0; i < ransomNote.size(); i++) {
            // mag[magazine[i]]++;
            nott[ransomNote[i]]++;
        }
        for (int i = 0; i < magazine.size(); i++) {
            // mag[magazine[i]]++;
            mag[magazine[i]]++;
        }

        for (const auto& x : nott) {
            if (mag[x.first] < nott[x.first]) {
                return false;
            }
        }
        return true;
    }
};