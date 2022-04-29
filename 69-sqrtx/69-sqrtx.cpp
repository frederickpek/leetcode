class Solution {
public:
    int mySqrt(int x) {
        long long target = x, ans;
        for (ans = 1; ans <= 46350; ++ans) {
            if (ans * ans > target) break;
        }
        return ans - 1;
    }
};