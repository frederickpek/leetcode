class Solution {
public:
    vector<int> twoSum(vector<int>& a, int T) {
        int l = 0, r = a.size() - 1;
        while (a[l] + a[r] != T) (a[l] + a[r] < T) ? ++l : --r;
        return vector<int> {l + 1, r + 1};
    }
};