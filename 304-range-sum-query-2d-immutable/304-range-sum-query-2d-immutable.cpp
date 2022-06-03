class NumMatrix {
public:
    vector<vector<int>> dp;
    
    NumMatrix(vector<vector<int>>& M) {
        dp = M;
        int n = M.size();
        int m = M[0].size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int N = i ? dp[i-1][j] : 0;
                int W = j ? dp[i][j-1] : 0;
                int NW = (i && j) ? dp[i-1][j-1] : 0;
                dp[i][j] += N + W - NW;
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        int N = r1 ? dp[r1-1][c2] : 0;
        int W = c1 ? dp[r2][c1-1] : 0;
        int NW = (r1 && c1) ? dp[r1-1][c1-1] : 0;
        return dp[r2][c2] - N - W + NW;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */