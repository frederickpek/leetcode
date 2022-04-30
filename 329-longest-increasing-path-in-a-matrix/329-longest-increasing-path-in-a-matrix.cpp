#define rep(i, n) for (int i = 0; i < n; ++i)

int n, m;
vector<int> indeg;
vector<vector<int>> al;

const int d4i[4] = {0, 0, 1, -1};
const int d4j[4] = {1, -1, 0, 0};

int idx(int i, int j) { return i * m + j; }
bool oob(int i, int j) { return i<0 || i>n-1 || j<0 || j>m-1; }

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& g) {
        n = g.size();
        m = g[0].size();
        indeg.assign(n*m, 0);
        al.assign(n*m, vector<int>());
        rep(i, n) rep(j, m) rep(k, 4) {
            int di = i + d4i[k];
            int dj = j + d4j[k];
            if (oob(di, dj) or g[i][j] >= g[di][dj]) continue;
            al[idx(i, j)].emplace_back(idx(di, dj));
            indeg[idx(di, dj)]++;
        }
        
        queue<int> q;
        rep(i, n) rep(j, m) if (!indeg[idx(i, j)]) q.emplace(idx(i, j));
        
        int ans = 0;
        int rem = n*m;
        while (rem > 0) {
            ans++;
            int cnt = q.size();
            rep(k, cnt) {
                rem--;
                auto u = q.front(); q.pop();
                for (auto v : al[u]) {
                    indeg[v]--;
                    if (indeg[v]) continue;
                    q.emplace(v);
                }
            }
        }
        
        return ans;
    }
};