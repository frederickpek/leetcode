class Solution {
public:
    int LCS(string &a, string &b) {
        int n = a.length(), m = b.length();
        int dp[n+1][m+1]; memset(dp, 0, sizeof dp);
        for (int j = 0; j < m; ++j) for (int i = 0; i < n; ++i)
            dp[i+1][j+1] = a[i] == b[j] ? dp[i][j] + 1 : max(dp[i][j+1], dp[i+1][j]);
        return dp[n][m];
    }
    
    int minDistance(string &a, string &b) {
        return a.length() + b.length() - 2 * LCS(a, b);
    }
};