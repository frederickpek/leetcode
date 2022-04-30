#define rep(i, n) for (int i = 0; i < n; ++i)

vector<int> vis;
vector<vector<int>> al;

void dfs(int u, vector<int>& vec) {
    vis[u] = 1;
    for (auto v : al[u]) {
        if (u==vec[0]-1 && v==vec[1]-1) continue;
        if (vis[v]) continue;
        dfs(v, vec);
    }
}

class Solution {
public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> indeg(n, 0);
        al.assign(n, vector<int>());
        for (auto vec : edges) {
            al[vec[0]-1].emplace_back(vec[1]-1);
            indeg[vec[1]-1]++;
        }
        int num_0s = 0;
        rep(u, n) num_0s += !indeg[u];
        reverse(edges.begin(), edges.end());
        for (auto vec : edges) {
            int u = vec[0]-1;
            int v = vec[1]-1;
            indeg[v]--;
            if (num_0s + !indeg[v] != 1) {
                indeg[v]++;
                continue;
            }
            rep(u, n) if (!indeg[u]) {
                vis.assign(n, 0);
                dfs(u, vec);
                int cnt = 0;
                rep(u, n) cnt += vis[u];
                if (cnt == n) return vec;
            }
            indeg[v]++;
        }
        return {-1, -1};
    }
};