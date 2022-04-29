#define rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    int removeElement(vector<int>& a, int val) {
        int k = 0;
        rep(i, a.size()) {
            if (a[i] == val) continue;
            a[k++] = a[i];
        }
        return k;
    }
};