class Solution {
public:
    int findLonelyPixel(vector<vector<char>>& picture) {
        int ans = 0;
        int m = picture.size();
        int n = picture[0].size();
        std::vector<int> cols(n, 0);
        std::vector<int> rows(m, 0);
        cout << m << " " << n << endl;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (picture[i][j] == 'B') {
                    cols[j]++;
                    rows[i]++;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (cols[j] == 1 && rows[i] == 1 && picture[i][j] == 'B') {
                    ans++;
                }
            }
        }
        return ans;
        // for (int i = 0; i < picture.size(); i++) {
        //     for (int j = 0; j < picture[i].size(); j++) {
        //         auto ch = picture[i][j];
        //         if (ch == 'B') {
        //             if (i > 0) {
        //                 if (picture[i-1][j] != 'W') {
        //                     continue;
        //                 }

        //             }
        //             if (i < picture.size()-1) {
        //                 if (picture[i+1][j] != 'W') {
        //                     continue;
        //                 }
        //             }
        //             if (j > 0) {
        //                 if (picture[i][j-1] != 'W') {
        //                     continue;
        //                 }
        //             }
        //             if (j < picture[i].size()-1) {
        //                 if (picture[i][j+1] != 'W') {
        //                     continue;
        //                 }
        //             }
        //             ans++;
        //         }
        //     }
        // }
        return ans;
    }
};