class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, l = 0;
        set<char> S;
        for (auto c : s) {
            while (S.count(c)) S.erase(s[l++]);
            S.insert(c);
            ans = max(ans, (int)S.size());
        }
        return ans;
    }
};