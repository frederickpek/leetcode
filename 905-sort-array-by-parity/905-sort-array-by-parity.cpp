class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        vector<int> ret;
        for (auto val : a) if (val%2==0) ret.emplace_back(val);
        for (auto val : a) if (val%2) ret.emplace_back(val);
        return ret;
    }
};