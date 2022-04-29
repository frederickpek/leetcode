#define rep(i, n) for (int i = 0; i < n; ++i)

class Solution {
public:
    vector<vector<int>> al;
    vector<int> indeg, vis, topo;

    void dfs(int u) {
        vis[u] = 1;
        topo.emplace_back(u);
        for (auto v : al[u]) {
            indeg[v]--;
            if (vis[v] || indeg[v]) continue;
            dfs(v);
        }
    }
    
    vector<int> findOrder(int n, vector<vector<int>>& edges) {
        vis.assign(n, 0);
        indeg.assign(n, 0);
        al.assign(n, vector<int>());
        for (auto vec : edges) {
            int v = vec[0], u = vec[1];
            indeg[v]++;
            al[u].emplace_back(v);
        }
        
        rep(u, n) if (!vis[u] && !indeg[u]) dfs(u);
        
        return (int)topo.size() == n ? topo : vector<int>();
    }
};