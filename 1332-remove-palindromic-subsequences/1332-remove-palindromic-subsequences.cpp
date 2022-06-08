class Solution {
public:
    bool is_palindrome(string &s) {
        string t = s;
        reverse(t.begin(), t.end());
        return t == s;
    }
    
    int removePalindromeSub(string s) {
        return is_palindrome(s) ? 1 : 2;
    }
};