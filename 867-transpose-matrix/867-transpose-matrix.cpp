#define rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& M) {
        int n = M.size(), m = M[0].size();
        vector<vector<int>> ret(m, vector<int>(n));
        rep(i, n) rep(j, m) ret[j][i] = M[i][j];
        return ret;
    }
};