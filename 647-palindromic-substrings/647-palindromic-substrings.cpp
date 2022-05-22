class Solution {
public:
    int n;
    bool oob(int i) { return i < 0 || i > n - 1; } 
    
    int search(string &s, int i, int j) {
        int ret = 0;
        while (!oob(i) && !oob(j) && s[i] == s[j]) {
            ++ret; --i; ++j;
        }
        return ret;
    }
    
    int countSubstrings(string s) {
        int ans = 0; n = s.length();
        for (int i = 0; i < n; ++i) {
            ans += search(s, i, i);
            ans += search(s, i, i+1);
        }
        return ans;
    }
};