class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if (k > s.size()) return 0;
        set<string> S;
        for (int i = 0; i <= s.size() - k; ++i) S.insert(s.substr(i, k));
        return S.size() == (1 << k);
    }
};