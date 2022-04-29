#define rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    vector<int> indeg, vis;
    vector<vector<int>> al;
    vector<set<int>> ancestors;

    void dfs(int u) {
        vis[u] = 1;
        for (auto v : al[u]) {
            indeg[v]--;
            ancestors[v].insert(u);
            for (auto t : ancestors[u]) ancestors[v].insert(t);
            if (!indeg[v]) dfs(v);
        }
    }
    
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vis.assign(n, 0);
        indeg.assign(n, 0);
        al.assign(n, vector<int>());
        ancestors.assign(n, set<int>());
        for (auto vec : edges) {
            int u = vec[0], v = vec[1];
            indeg[v]++;
            al[u].emplace_back(v);
        }
        rep(u, n) if (!vis[u] && !indeg[u]) dfs(u);
    
        vector<vector<int>> ret(n, vector<int>());
        rep(u, n) for (auto a : ancestors[u]) ret[u].emplace_back(a);
        return ret;
    }
};