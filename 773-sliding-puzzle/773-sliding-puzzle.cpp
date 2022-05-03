class Solution {
public:
    vector<vector<int>> d6 = {{1, 3}, {0, 2, 4}, {1, 5}, {0, 4}, {1, 3, 5}, {2, 4}};
    int slidingPuzzle(vector<vector<int>>& b) {
        string s = "";
        set<string> vis;
        for (auto v : b) for (auto i : v) s.push_back('0' + i);
        
        queue<pair<string,int>> q;
        q.emplace(s, 0);

        while (q.size()) {
            auto [u, d] = q.front(); q.pop();
            if (u == "123450") return d;
            int i = u.find('0');
            for (auto di : d6[i]) {
                string v = u;
                swap(v[i], v[di]);
                if (vis.count(v)) continue;
                vis.insert(v);
                q.emplace(v, d+1);
            }
        }
        
        return -1;
    }
};