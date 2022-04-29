#define rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        bool dp[n][n];
        memset(dp, 0, sizeof dp);
        rep(i, n) dp[i][i] = 1;
        
        int start = 0;
        int ans = 1;
        rep(i, n-1) if (s[i] == s[i+1]) {
            ans = 2;
            start = i;
            dp[i][i+1] = 1;
        }
        
        for (int len = 3; len <= n; ++len) {
            rep(i, n-len+1) {
                int j = i+len-1;
                if (!dp[i+1][j-1] || (s[i] != s[j])) continue;
                dp[i][j] = 1;
                if (ans < len) {
                    ans = len;
                    start = i;
                }
            }
        }
        
        return s.substr(start, ans);
    }
};