class Solution {
public:
    int minCostClimbingStairs(vector<int>& a) {
        a.push_back(0);
        int s1 = 0, s2 = 0, s0;
        for (int i = 2; i < a.size(); ++i) {
            s0 = s2;
            s2 = min(a[i-1] + s2, a[i-2] + s1);
            s1 = s0;
        }
        return s2;
    }
};