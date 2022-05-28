#define rep(i, n) for (int i = 0; i < n; ++i)

const int d4i[4] = {1, -1, 0, 0};
const int d4j[4] = {0, 0, 1, -1};

class Solution {
public:
    int n, m, T;
    bool oob(int i, int j) {
        return i < 0 || i > n-1 || j < 0 || j > m-1;
    }
    
    int dfs(int i, int j, vector<vector<int>>& g, vector<vector<int>> &vis, int sum) {
        int ret = 0;
        sum++;
        vis[i][j] = 1;
        if (g[i][j] == 2 && sum == T) return 1;
        rep(k, 4) {
            int di = i + d4i[k];
            int dj = j + d4j[k];
            if (oob(di, dj) || vis[di][dj] || g[di][dj] == -1) continue;
            vector<vector<int>> v = vis;
            ret += dfs(di, dj, g, v, sum);
        }
        return ret;
    }
    
    int uniquePathsIII(vector<vector<int>>& g) {
        n = g.size();
        m = g[0].size();
        T = 0;
        int si = -1, sj = -1;
        rep(i, n) rep(j, m) {
            T += g[i][j] != -1;
            if (g[i][j] != 1) continue;
            si = i;
            sj = j;
        }
        vector<vector<int>> vis(n, vector<int>(m, 0));
        return dfs(si, sj, g, vis, 0);
    }
};