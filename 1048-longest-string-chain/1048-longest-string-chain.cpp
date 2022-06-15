#define rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    int n;
    vector<int> vis, topo;
    vector<vector<int>> al;
    
    bool is_pred(string &p, string &s) {
        if (p.length() + 1 != s.length()) return 0;
        int i = 0, j = 0, num = 0;
        while (i < p.length() && j < s.length()) {
            while (p[i] != s[j] && j < s.length()) {
                ++num;
                ++j;
                if (num > 1) return 0;
            }
            ++i; ++j;
        }
        return 1;
    }
    
    void dfs(int u) {
        vis[u] = 1;
        for (auto v : al[u]) {
            if (vis[v]) continue;
            dfs(v);
        }
        topo.emplace_back(u);
    }
    
    int lp_dag() {
        int ans = 0;
        int D[n]; memset(D, 0, sizeof D);
        for (int u : topo) for (int v : al[u]) {
            D[v] = max(D[v], D[u] + 1);
            ans = max(ans, D[v]);
        }
        return ans + 1;
    }
    
    int longestStrChain(vector<string>& w) {
        n = w.size();
        al.assign(n, vector<int>());
        rep(u, n) rep(v, n) if (is_pred(w[u], w[v])) al[u].emplace_back(v);
        vis.assign(n, 0);
	    rep(u, n) if (!vis[u]) dfs(u);
	    reverse(topo.begin(), topo.end());
        return lp_dag();
    }
};