class Solution {
public:
    int LIS(vector<int> &A) {
        int n = A.size(), k = 0, lis_end = 0;
        vector<int> p(n, -1), L(n, 0), L_id(n, 0);

        for (int i = 0; i < n; ++i) {
            int pos = lower_bound(L.begin(), L.begin()+k, A[i]) - L.begin();
            L[pos] = A[i];
            L_id[pos] = i;
            p[i] = pos ? L_id[pos-1] : -1;
            if (pos == k) {
                k = pos+1;
                lis_end = i;
            }
        }

        return k;
    }
    
    int maxEnvelopes(vector<vector<int>>& E) {
        sort(E.begin(), E.end(), [](auto& a, auto& b) {
            if (a[0] == b[0]) return b[1] < a[1];
            return a[0] < b[0];
        });
        
        vector<int> A;
        for (auto v : E) A.emplace_back(v[1]);
        return LIS(A);
    }
};