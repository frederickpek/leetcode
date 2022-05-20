class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& g) {
        int n = g.size();
        int m = g[0].size();
        int dp[n+1][m+1]; memset(dp, 0, sizeof dp); dp[0][1] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (g[i-1][j-1]) continue;
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n][m];
    }
};