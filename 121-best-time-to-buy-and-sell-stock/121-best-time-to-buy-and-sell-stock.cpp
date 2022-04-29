class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int lo = 1e9;
        for (auto p : prices) {
            lo = min(lo, p);
            ans = max(ans, p - lo);
        }
        return ans;
    }
};