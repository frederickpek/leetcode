#define rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    int firstMissingPositive(vector<int>& a) {
        int n = a.size();
        int has_one = 0;
        rep(i, n) {
            has_one |= a[i] == 1;
            if (a[i] > 0) continue;
            a[i] = 1;
        }
        if (!has_one) return 1;
        rep(i, n) if (abs(a[i]) <= a.size())
            a[abs(a[i])-1] = -abs(a[abs(a[i])-1]);
        a.emplace_back(1);
        rep(i, n+1) if (a[i] > 0) return i + 1;
        return -1;
    }
};