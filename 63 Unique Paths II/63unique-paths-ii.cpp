class Solution {
public:
    long long dp[102] = {0};
    // void fill(int i, int j) {
    //     if (dp[i][j] != 0) {
    //         return;
    //     }

    //     // std::cout << i << " " << j << std::endl;
    //     std::cout << dp[i+1][j] << std::endl;
    //     std::cout << dp[i][j+1] << std::endl;

    //     dp[i][j] = dp[i+1][j] + dp[i][j+1];
    // }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        // for (int i = m-1; i > -1; i--) {
        //     if (obstacleGrid[i][n-1] == 1) {
        //         set_i = 0;
        //     }
        //     dp[i][n-1] = set_i;
        // }
        // for (int j = n-1; j > -1; j--) {
        //     if (obstacleGrid[m-1][j] == 1) {
        //         set_j = 0;
        //     }
        //     dp[j] = set_j;
        // }
        dp[n-1] = (obstacleGrid[m-1][n-1] == 0) ? 1 : 0;
        // fill(m, n);
        // return -1;
        for (int i = m-1; i > -1; i--){
            for (int j = n-1; j > -1; j--) {
                if (obstacleGrid[i][j] == 1) {
                    dp[j] = 0;
                } else {
                    dp[j] += dp[j+1];
                }
                // fill(i, j);
            }
        }
        return dp[0];
    }
};