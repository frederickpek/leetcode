#define rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    const int inf = 1e9;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> D(n, inf); D[k-1] = 0;
        rep(k, n-1) for (auto &vec : times) {
            int u = vec[0]-1, v = vec[1]-1, w = vec[2];
            if (D[u] + w < D[v]) D[v] = D[u] + w;
        }
        int ans = -1;
        rep(u, n) ans = max(ans, D[u]);
        return ans == inf ? -1 : ans;
    }
};