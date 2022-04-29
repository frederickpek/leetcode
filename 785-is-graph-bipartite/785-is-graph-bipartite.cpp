#define rep(i, n) for (int i = 0; i < n; ++i)

class Solution {
public:
    bool is_bipartite = 1;
    vector<int> vis, col;
    
    void dfs(vector<vector<int>>& al, int u, int c) {
        vis[u] = 1;
        col[u] = c;
        for (auto v : al[u]) {
            if (vis[v]) {
                is_bipartite &= col[u] != col[v];
                continue;
            }
            dfs(al, v, !c);
        }
    }
    
    bool isBipartite(vector<vector<int>>& al) {
        int n = (int)al.size();
        vis.assign(n, 0);
        col.assign(n, -1);
        rep(u, n) if (!vis[u]) dfs(al, u, 0);
        return is_bipartite;
    }
};