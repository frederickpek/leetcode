class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string t = strs[0];
        for (string &s : strs) {
            int n = t.length();
            int m = s.length();
            string next = "";
            for (int i = 0; i < min(n, m); i++) {
                if (t[i] != s[i]) break;
                next.push_back(t[i]);
            }
            t = next;
        }
        return t;
    }
};