#define rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    int longestPath(vector<int>& p, string s) {
        int n = s.length();
        vector<int> D(n, 1);
        vector<vector<int>> al(n, vector<int>());
        rep(u, n-1) al[p[u+1]].emplace_back(u+1);
        int ans = 1;
        function<void(int)> dfs = [&ans, &al, &s, &D, &dfs](int u) {
            for (auto v : al[u]) {
                dfs(v);
                if (s[u] == s[v]) continue;
                ans = max(ans, D[u] + D[v]);
                D[u] = max(D[u], D[v] + 1);
            }
        };
        dfs(0);
        return ans;
    }
};