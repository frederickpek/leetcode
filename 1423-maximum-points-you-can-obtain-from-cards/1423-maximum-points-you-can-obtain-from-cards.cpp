class Solution {
public:
    int maxScore(vector<int>& a, int k) {
        int sum = accumulate(a.begin(), a.begin() + k, 0);
        int ans = sum, n = a.size();
        for (int i = 0; i < k; i++) {
            sum -= a[k-1-i];
            sum += a[n-1-i];
            ans = max(ans, sum);
        }
        return ans;
    }
};