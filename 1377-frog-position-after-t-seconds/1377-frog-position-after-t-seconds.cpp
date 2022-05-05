class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> al(n, vector<int>());
        for (auto &vec : edges) {
            al[vec[0]-1].emplace_back(vec[1]-1);
            al[vec[1]-1].emplace_back(vec[0]-1);
        }
        
        int rnd = 0;
        vector<int> vis(n, 0);
        vector<long long> p(n, 1);
        queue<int> q; q.emplace(0); vis[0] = 1e9;
        while (rnd < t && q.size()) {
            rnd++;
            int sz = q.size();
            for (int k = 0; k < sz; ++k) {
                auto u = q.front(); q.pop();
                long long cnt = 0;
                for (auto v : al[u]) if (!vis[v]) cnt++;
                if (cnt == 0) vis[u] = -1;
                for (auto v : al[u]) if (!vis[v]) {
                    p[v] = p[u] * cnt;
                    vis[v] = rnd;
                    q.emplace(v);
                }
            }
        }
        
        int u = target - 1;
        return (vis[u] == -1 || vis[u] == t) ? (double)1/p[u] : 0;
    }
};