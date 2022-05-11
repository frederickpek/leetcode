class Solution {
public:
    int countVowelStrings(int n) {
        int ans = 1;
        int v[5][2]; memset(v, 0, sizeof v);
        int prev = 0, curr = 1;
        for (int k = 0; k < n; ++k) {
            int sum = 0;
            for (int i = 0; i < 5; ++i) {
                v[i][curr] = i ? ans -= v[i-1][prev] : ans;
                sum += v[i][curr];
            }
            ans = sum;
            prev ^= 1;
            curr ^= 1;
        }
        return ans;
    }
};