class Solution {
public:
    long long countPairs(vector<int>& a, int k) {
        long long ans = 0;
        unordered_map<int,int> M;
        
        for(int i = 0; i < a.size(); ++i) {
            int gcd = __gcd(a[i], k);
            for (auto &[v, f] : M) if (v%(k/gcd)==0) ans += f;
            M[gcd]++;
        }

        return ans;
    }
};