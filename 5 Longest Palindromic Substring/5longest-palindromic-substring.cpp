class Solution {
public:
    // string lps(const string& s, int i, int j) {
    //     if (i == j) {
    //         // return 1;
    //         return std::string{s[i]};
    //     }
    //     if (i > j) {
    //         // return 0;
    //         return {};
    //     }
    //     if (s[i] == s[j]) {
    //         string middles = lps(i+1, j-1);
    //         string iPlus = lps(i+1, j);
    //         string jMinus = lps(i, j-1);
    //         string ret = iPlus.size() > jMinus.size() ? jPlus : jMinus;
    //         ret = 2+middles.size() > ret.size() ? middles : ret;
    //         return ret;
    //         // int NEW = 2 + lps(i+1, j-1).size();
    //         // int others = std::max(lps(i+1, j), lps(i, j-1));
    //         // return std::max(NEW, others);
    //     }
    //     else {
    //         string iPlus = lps(i+1, j);
    //         string jMinus = lps(i, j-1);
    //         string ret = iPlus.size() > jMinus.size() ? jPlus : jMinus;
    //         return ret;
    //         // return std::max(lps(i+1, j), lps(i, j-1));
    //     }

    // }
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n+2, vector<bool>(n+2, false));
        // vector<vector<string>> dp(s.size()+2, vector<string>(s.size()+2, ""));
        
        int start = 0;
        int maxLen = 1;
        for (int i = n; i >= 1; i--) {
            for (int j = 1; j <= s.size(); j++) {
                if (i == j) {
                    // std::string ss(1, s[i-1]); 
                    // cout << ss << endl;
                    dp[i][j] = true;
                }
                else if (i > j) {
                    continue;
                    dp[i][j] = false;
                }
                else if (s[i-1] != s[j-1]) {
                    // string iPlus = dp[i+1][j];
                    // string jMinus = dp[i][j-1];
                    // string ret = iPlus.size() > jMinus.size() ? iPlus : jMinus;
                    dp[i][j] = false;
                }
                else if (s[i-1] == s[j-1]) {
                    // string iPlus = dp[i+1][j];
                    // string jMinus = dp[i][j-1];
                    // string ret = iPlus.size() > jMinus.size() ? iPlus : jMinus;
                    // string middles = dp[i+1][j-1];
                    // if (dp[i+1][j-1].size() == (j-1)-(i+1)+1) {
                    //     middles = s[i-1] + dp[i+1][j-1] + s[j-1];
                    // }
                    // ret = middles.size() > ret.size() ? middles : ret;
                    if (i == j-1) {
                        dp[i][j] = true;
                    }
                    else {
                        dp[i][j] = dp[i+1][j-1];
                    }
                }
                if (dp[i][j] && maxLen < j-i+1) {
                    start = i-1;
                    maxLen = j-i+1;
                }
            }
        }
        // for (int i = 0; i < dp.size(); i++) {
        //     for (int j = 0; j < dp[0].size(); j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return s.substr(start, maxLen);
    }
};