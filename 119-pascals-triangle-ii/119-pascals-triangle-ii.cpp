class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        for (int i = 0; i < numRows; ++i) {
            vector<int> v(i+1, 1);
            for (int j = 1; j < i; ++j) {
                if (i-1 < 0) continue;
                v[j] = ret[i-1][j] + ret[i-1][j-1];
            }
            ret.emplace_back(v);
        }
        return ret;
    }
    vector<int> getRow(int rowIndex) {
        return generate(rowIndex + 1).back();
    }
};