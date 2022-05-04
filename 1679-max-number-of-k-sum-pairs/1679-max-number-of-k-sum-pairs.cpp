class Solution {
public:
    int maxOperations(vector<int>& a, int k) {
        map<int,int> M;
        for (auto val : a) M[val]++;
        int ans = 0;
        for (auto val : a) {
            if (!M[val]) continue;
            M[val]--;
            if (!M.count(k - val)) continue;
            if (!M[k - val]) continue;
            M[k - val]--;
            ans++;
        }
        return ans;
    }
};