#define rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        queue<int> q;
        vector<int> indeg(n, 0);
        vector<vector<int>> al(n, vector<int>());
        for (auto vec : edges) {
            int u = vec[0], v = vec[1];
            al[u].emplace_back(v);
            al[v].emplace_back(u);
            indeg[u]++;
            indeg[v]++;
        }
        
        rep(u, n) if (indeg[u]==1) q.emplace(u);
        
        int rem = n;
        while (rem > 2) {
            int round = q.size();
            rep(k, round) {
                auto u = q.front(); q.pop();
                indeg[u]--;
                for (auto v : al[u]) {
                    if (indeg[v] == 0) continue;
                    indeg[v]--;
                    rem--;
                    if (indeg[v]==1) q.emplace(v);
                }
            }
        }
        
        vector<int> sol;
        while (q.size()) {
            sol.emplace_back(q.front());
            q.pop();
        }
        return n == 1 ? vector<int>(1, 0) : sol;
    }
};