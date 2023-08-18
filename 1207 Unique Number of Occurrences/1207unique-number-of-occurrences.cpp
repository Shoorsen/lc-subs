class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int,int> mp;
        for (int i : arr) {
            mp[i]++;
        }
        set<int> s;
        int counter = 0;
        for (const auto& pair : mp) {
            s.insert(pair.second);
            counter++;
        }
        if (s.size() != counter) {
            return false;
        }
        return true;
    }
};