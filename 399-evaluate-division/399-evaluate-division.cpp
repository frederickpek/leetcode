#define rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    vector<int> vis;
    vector<vector<pair<int,double>>> al;
    
    double dfs(int u, int t, double res) {
        vis[u] = 1;
        if (u == t) return res;
        for (auto [v, w] : al[u]) {
            if (vis[v]) continue;
            double cand = dfs(v, t, res * w);
            if (cand != -1.0) return cand;
        }
        return -1.0;
    }
    
    vector<double> calcEquation(vector<vector<string>>& E, vector<double>& V, vector<vector<string>>& Q) {
        int i = E.size();
        map<string,int> M;
        rep(i, E.size()) {
            string u = E[i][0];
            string v = E[i][1];
            if (!M.count(u)) M[u] = M.size();
            if (!M.count(v)) M[v] = M.size();
        }
        
        int n = M.size();
        al.assign(n, vector<pair<int,double>>());
        rep(i, E.size()) {
            string u = E[i][0];
            string v = E[i][1];
            double w = V[i];
            al[M[u]].emplace_back(M[v], w);
            al[M[v]].emplace_back(M[u], 1/w);
        }
        
        vector<double> ret;
        rep(i, Q.size()) {
            string u = Q[i][0];
            string v = Q[i][1];
            if (M.count(u) && M.count(v)) {
                vis.assign(n, 0);
                ret.emplace_back(dfs(M[u], M[v], 1.0));
            } else ret.emplace_back(-1.0);
        }
        
        return ret;
    }
};