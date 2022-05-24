class Solution {
public:
    int longestValidParentheses(string s) {
        int sum = 0, ans = 0, len = 0;
        for (auto c : s) {
            c == '(' ? sum++ : sum--;
            if (sum < 0) {
                sum = 0;
                len = 0;
                continue;
            }
            len++;
            if (sum == 0) ans = max(ans, len);
        }
        sum = 0, len = 0;
        reverse(s.begin(), s.end());
        for (auto c : s) {
            c == ')' ? sum++ : sum--;
            if (sum < 0) {
                sum = 0;
                len = 0;
                continue;
            }
            len++;
            if (sum == 0) ans = max(ans, len);
        }
        return ans;
    }
};