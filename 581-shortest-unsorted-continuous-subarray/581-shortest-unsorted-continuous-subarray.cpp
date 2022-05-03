class Solution {
public:
    int findUnsortedSubarray(vector<int>& a) {
        vector<int> b = a;
        sort(b.begin(), b.end());
        int i = 0, j = b.size() - 1;
        while (i < a.size()) if (a[i]!=b[i++]) break;
        while (j >= 0) if (a[j]!=b[j--]) break;
        return (i-1 < j+1) ? j - i + 3 : 0;
    }
};