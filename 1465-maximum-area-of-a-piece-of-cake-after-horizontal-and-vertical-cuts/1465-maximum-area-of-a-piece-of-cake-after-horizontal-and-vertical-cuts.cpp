class Solution {
public:
    int maxArea(int h, int w, vector<int>& a, vector<int>& b) {
        a.push_back(0); a.push_back(h); sort(a.begin(), a.end());
        b.push_back(0); b.push_back(w); sort(b.begin(), b.end());
        int H = 0, W = 0;
        for (int i = 1; i < a.size(); ++i) H = max(H, a[i] - a[i-1]);
        for (int i = 1; i < b.size(); ++i) W = max(W, b[i] - b[i-1]);
        return ((long long) H * W) % (int)(1e9 + 7);
    }
};