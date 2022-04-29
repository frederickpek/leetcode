#define rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    string addBinary(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(a.length(), b.length()) + 1;
        while (a.length() < n) a.push_back('0');
        while (b.length() < n) b.push_back('0');
        
        int carry = 0;
        string sol = "";
        rep(i, n) {
            int A = a[i] - '0';
            int B = b[i] - '0';
            int sum = A + B + carry;
            int res = sum % 2;
            carry = sum / 2;
            if (i == n-1 && res == 0) continue;
            sol.push_back(char(res + '0'));
        }
        reverse(sol.begin(), sol.end());
        return sol;
    }
};