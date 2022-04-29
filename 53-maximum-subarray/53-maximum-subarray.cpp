#define rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    int maxSubArray(vector<int>& a) {
        int ans = a[0];
        int sum = 0;
        rep(i, a.size()) {
            sum += a[i];
            ans = max({a[i], sum, ans});
            if (sum < 0) sum = 0;
        }
        return ans;
    }
};