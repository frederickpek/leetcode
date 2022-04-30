#define rep(i, n) for (int i = 0; i < n; ++i)

vector<string> ans;
map<string,multiset<string>> al;

void dfs(string u) {
    while (al[u].size()) {
        string v = *al[u].begin();
        al[u].erase(al[u].begin());
        dfs(v);
    }
    ans.emplace_back(u);
}

class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        al.clear();
        ans.clear();
        rep(i, tickets.size()) {
            string u = tickets[i][0];
            string v = tickets[i][1];
            al[u].insert(v);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};