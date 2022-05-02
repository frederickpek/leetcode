#define rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    int arrayPairSum(vector<int>& a) {
        sort(a.begin(), a.end());
        int ans = 0;
        rep(i, a.size()/2) ans += min(a[i*2], a[i*2+1]);
        return ans;
    }
};