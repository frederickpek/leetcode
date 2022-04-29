class Solution {
public:
    string convert(string s, int numRows) {
        vector<tuple<int,int,int>> v;
        int r = 0, c = 0;
        int n = s.length();
        bool down = 1;
        for (int i = 0; i < n; ++i) {
            v.emplace_back(r, c, i);
            down ? ++r : --r;
            if (!down) c++;
            if (down && r == numRows-1) down = 0;
            if (!down && r == 0) down = 1;
        }
        sort(v.begin(), v.end());
        string t;
        for (auto &[r, c, i] : v) t.push_back(s[i]);
        return t;
    }
};