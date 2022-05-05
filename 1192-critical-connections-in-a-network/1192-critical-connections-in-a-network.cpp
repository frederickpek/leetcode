class Solution {
public:
    int cnt;
    vector<int> vis, num, low;
    vector<vector<int>> al, bridges;

    void dfs(int u, int p) {
        vis[u] = 1;
        num[u] = low[u] = cnt++;
        for (auto v : al[u]) {
            if (v == p) continue;
            if (vis[v]) {
                low[u] = min(low[u], num[v]);
                continue;
            }
            dfs(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] > num[u]) bridges.push_back({u, v});
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& g) {
        al.assign(n, vector<int>());
        for (auto &vec : g) {
            al[vec[0]].emplace_back(vec[1]);
            al[vec[1]].emplace_back(vec[0]);
        }
        cnt = 0;
        vis.assign(n, 0);
        num.assign(n, -1);
        low.assign(n, -1);
        for (int i = 0; i < n; ++i) if (!vis[i]) dfs(i, -1);
        return bridges;
    }
};