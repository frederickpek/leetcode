class Solution {
public:
    const int d4i[4] = {0, 0, 1, -1};
    const int d4j[4] = {1, -1, 0, 0};
    
    bool can(vector<vector<int>>& g, int k) {
        int n = (int)g.size();
        int m = (int)g[0].size();
        auto oob = [n, m](int i, int j) { return i < 0 || i > n-1 || j < 0 || j > m-1; };
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<int,int>> q;
        q.emplace(0, 0);
        vis[0][0] = 1;
        
        while (q.size()) {
            auto [i, j] = q.front(); q.pop();
            if (i == n-1 && j == m-1) return 1;
            
            for (int d = 0; d < 4; d++) {
                int di = i + d4i[d];
                int dj = j + d4j[d];
                if (oob(di, dj) || vis[di][dj])continue;
                if (abs(g[i][j]-g[di][dj]) > k) continue;
                q.emplace(di, dj);
                vis[di][dj] = 1;
            }
        }
        
        return 0;
    }
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int lo = 0, mid, hi = 1e6;
        while (lo < hi - 1) {
            mid = (lo + hi) / 2;
            can(heights, mid) ? hi = mid : lo = mid;
        }
        return can(heights, lo) ? lo : hi;
    }
};
