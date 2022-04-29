#define rep(i, n) for (int i = 0; i < n; i++)

class Solution {
public:
    const int removed = -1e9;
    int removeDuplicates(vector<int>& a) {
        int n = (int)a.size();
        rep(i, n-1) {
            if (a[i]!=a[i+1]) continue;
            a[i] = removed;
        }
        int k = 0;
        rep(i, n) {
            if (a[i] == removed) continue;
            a[k++] = a[i];
        }
        return k;
    }
};