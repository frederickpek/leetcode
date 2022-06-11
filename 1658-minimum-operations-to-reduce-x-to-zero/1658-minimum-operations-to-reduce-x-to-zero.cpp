class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int ans = 1e9, n = a.size();
        map<int,int> M; M[0] = 0;
        
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[i];
            M[sum] += i + 1; // wont have duplicates, a[i] > 0
            if (sum == x) ans = i + 1;
        }
        
        sum = 0;
        for (int i = 0; i < n; ++i) {
            sum += a[n - 1 - i];
            if (!M.count(x - sum) or M[x - sum] >= n - i) continue;
            ans = min(ans, M[x - sum] + i + 1);
        }
        
        return ans == 1e9 ? -1 : ans;
    }
};