class Solution {
public:
    int maximumUniqueSubarray(vector<int>& a) {
        int l = 0, sum = 0, ans = 0;
        set<int> S;
        
        for (auto val : a) {
            while (S.count(val)) {
                S.erase(a[l]);
                sum -= a[l++];
            }
            S.insert(val);
            sum += val;
            ans = max(ans, sum);
        }
        
        return ans;
    }
};