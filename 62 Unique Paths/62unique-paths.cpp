class Solution {
public:
    int dp[101][101] = {0};

    int called = 0;
    int glob_m, glob_n;
    void fill(int i, int j) {
        if (dp[i][j] != 0) {
            return;
        }
        dp[i][j] = dp[i+1][j] + dp[i][j+1];
    }
    int uniquePaths(int m, int n) {
        for (int i = 0; i < m; i++) {
            std::cout << i << " " << n-1 << std::endl;
            dp[i][n-1] = 1;
        }
        for (int j = 0; j < n; j++) {
            dp[m-1][j] = 1;
        }
        for (int i = m-1; i > -1; i--) {
            for (int j = n-1; j > -1; j--) {
                fill(i, j);
            }
        }
        return dp[0][0];
    }

};