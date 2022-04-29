#define rep(i, n) for (int i = 0; i < n; ++i)

class Solution {
public:
    vector<int> indeg, vis;
    vector<vector<int>> al;

    void dfs(int u) {
        vis[u] = 1;
        for (auto v : al[u]) {
            indeg[v]--;
            if (vis[v] || indeg[v]) continue;
            dfs(v);
        }
    }
    
    bool canFinish(int n, vector<vector<int>>& edges) {
        vis.assign(n, 0);
        indeg.assign(n, 0);
        al.assign(n, vector<int>());
        for (auto vec : edges) {
            int v = vec[0], u = vec[1];
            indeg[v]++;
            al[u].emplace_back(v);
        }
        
        rep(u, n) if (!vis[u] && !indeg[u]) dfs(u);
        
        bool ret = 1;
        rep(u, n) ret &= vis[u];
        return ret;
    }
};