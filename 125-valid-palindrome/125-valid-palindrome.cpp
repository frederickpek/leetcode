class Solution {
public:
    bool isPalindrome(string s) {
        string t = "";
        for (char &c : s) {
            c = tolower(c);
            if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
                t.push_back(c);
        }
        int n = t.length();
        for (int i = 0; i < (n/2); i++) {
            if (t[i] != t[n-1-i]) return 0;
        }
        return 1;
    }
};