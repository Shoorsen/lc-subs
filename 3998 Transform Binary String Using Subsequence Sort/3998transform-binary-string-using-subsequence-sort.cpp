class Solution {
public:
    std::pair<int, int> getOnesZeros(string s) {
        int ones = 0;
        int zeros = 0;
        for (const char& ch : s) {
            if (ch == '1') {
                ones++;
            } else if (ch == '0') {
                zeros++;
            }
        }
        return std::make_pair(ones, zeros);
    }
    int getStartOnes(string s) {
        int startOnes = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                startOnes++;
            } else {
                break;
            }
        }
        return startOnes;
    }
    // int getEndZeros(string s) {
    //     int endZeros = 0;
    //     for (int i = s.size()-1; i >= 0; i--) {
    //         if (s[i] == '0') {
    //             endZeros++;
    //         } else {
    //             break;
    //         }
    //     }
    //     return endZeros;
    // }

    vector<bool> transformStr(string s, vector<string>& strs) {
        auto [ones, zeros] = getOnesZeros(s);
        std::vector<bool> ans;
        int sStartOnes = getStartOnes(s);
        // int sEndZeros = getEndZeros(s);
        for (int t = 0; t < strs.size(); t++) {
            auto [sOnes, sZeros] = getOnesZeros(strs[t]);
            // int qMarks = strs[t].size() - sOnes + sZeros;
            // int strsStartOnes = getStartOnes(strs[t]);
            // // int strsEndZeros = getEndZeros(strs[t]);
            if (sOnes > ones || sZeros > zeros) {
                ans.push_back(false);
                continue;
            }//else {
            //     ans.push_back(true);
            // }
            int scount = 0;
            int strscount = 0;
            bool toapp = true;
            for (int i = 0; i < strs[t].size(); i++) {
                if (s[i]=='1') {
                    scount++;
                }
                if (strs[t][i] == '1') {
                    strscount++;
                }
                if (strscount > scount) {
                    toapp = false;
                    break;
                }
            }
            scount = 0;
            strscount = 0;
            for (int i = strs[t].size()-1; i >= 0; i--) {
                if (s[i] == '0') {
                    scount++;
                }
                if (strs[t][i] == '0') {
                    strscount++;
                }
                if (strscount > scount) {
                    toapp = false;
                    break;
                }
            }
            ans.push_back(toapp);
        }
        return ans;
    }
};
