class Solution {
public:
    int minSwapsCouples(vector<int>& a) {
        vector<int> M(a.size());
        for (int i = 0; i < a.size(); i++) M[a[i]] = i;
        
        int i = 0, ans = 0;
        while (i < a.size()) {
            int b = a[i]%2 ? a[i] - 1 : a[i] + 1;
            if (a[i+1] != b) {
                int j = M[b];
                swap(M[a[i+1]], M[b]);
                swap(a[i+1], a[j]);
                ans++;
            }
            i += 2;
        }
        
        return ans;
    }
};