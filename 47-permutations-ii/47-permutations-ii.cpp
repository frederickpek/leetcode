class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& a) {
        set<vector<int>> S;
        sort(a.begin(), a.end());
        do S.insert(a);
        while (next_permutation(a.begin(), a.end()));
        vector<vector<int>> ret;
        for (auto v : S) ret.emplace_back(v);
        return ret;
    }
};