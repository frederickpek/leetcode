class Solution {
public:
    bool checkPossibility(vector<int>& a) {
        int n = a.size(), c1 = 0, c2 = 0;
        vector<int> b = a;
        for (int i = 1; i < n; ++i) {
            if (a[i-1] <= a[i]) continue;
            a[i] = a[i-1];
            ++c1;
        }
        for (int i = n-1; i; --i) {
            if (b[i-1] <= b[i]) continue;
            b[i-1] = b[i];
            ++c2;
        }
        return c1 <= 1 || c2 <= 1;
    }
};