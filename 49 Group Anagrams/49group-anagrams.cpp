class Solution {
public:

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        std::map<std::vector<char>, std::vector<std::string>> mp;
        for (int i = 0; i < strs.size(); i++) {
            std::vector<char> v(26, 0);
            for (int j = 0; j < strs[i].size(); j++) {
                // cout << strs[i][j]-'a' << endl;
                v[strs[i][j]-'a'] += 1;
                // v[strs[i][j]] += 1;
            }
            mp[v].push_back(strs[i]);
        }
        std::vector<std::vector<std::string>> ans;
        for (const auto& pair : mp) {
            ans.push_back(pair.second);
        }
        return ans;
    }
};