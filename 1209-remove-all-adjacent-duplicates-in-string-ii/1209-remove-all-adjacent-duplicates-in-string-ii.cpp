class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>> S;
        for (char c : s) {
            if (S.empty() || S.top().first != c) {
                S.push({c, 1});
                continue;
            }
            if (++S.top().second == k) S.pop();
        }
        string t = "";
        while (S.size()) {
            auto [c, cnt] = S.top(); S.pop();
            for (int i = 0; i < cnt; i++) t.push_back(c);
        }
        reverse(t.begin(), t.end());
        return t;
    }
};