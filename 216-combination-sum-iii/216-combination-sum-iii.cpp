#define rep(i, n) for (int i = 0; i < n; ++i)
#define for_nCk(s, n, k) \
  for (int s = (1 << k) - 1, tmp_var = 0; s < (1 << n); \
  tmp_var = s | (s - 1), s = (tmp_var + 1) | (((~tmp_var & -~tmp_var) - 1) >> (__builtin_ctz(s) + 1)))
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int target) {
        int n = 9;
        vector<vector<int>> ret;
        for_nCk(m, n, k) {
            int sum = 0;
            vector<int> curr;
            rep(i, n) if ((1<<i) & m) {
                sum += i+1;
                curr.emplace_back(i+1);
            }
            if (sum == target) ret.emplace_back(curr);
        }
        return ret;
    }
};