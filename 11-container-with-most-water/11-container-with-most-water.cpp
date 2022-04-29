class Solution {
public:
    int maxArea(vector<int>& a) {
        int i = 0, j = a.size()-1;
        int ans = 0;
        while (i < j) {
            ans = max(ans, min(a[i], a[j])*(j-i));
            (a[i] < a[j]) ? ++i : --j;
        }
        return ans;
    }
};