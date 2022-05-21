class Solution {
public:
    int coinChange(vector<int>& C, int T) {
        int n = C.size();
        int dp[T+1]; memset(dp, -1, sizeof dp); dp[0] = 0;
        for (int curr = 1; curr <= T; ++curr) {
            for (int j = 0; j < n; ++j) {
                if (C[j] > curr) continue;
                int& prev = dp[curr - C[j]];
                if (prev == -1) continue;
                dp[curr] = (dp[curr] == -1) ? prev + 1 : min(dp[curr], prev + 1);
            }
        }
        return dp[T];
    }
};