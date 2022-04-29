#define rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int M = (int)nums1.size();
        rep(i, m) nums1[M-1-i] = nums1[m-1-i];
        int i = 0, j = 0;
        int k = 0;
        while (i < m || j < n) {
            int v1 = i < m ? nums1[M-m+i] : 2e9;
            int v2 = j < n ? nums2[j] : 2e9;
            nums1[k++] = v1 < v2 ? v1 : v2;
            v1 < v2 ? ++i : ++j;
        }
    }
};