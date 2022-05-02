class Solution {
public:
    int largestRectangleArea(vector<int>& H) {
        int n = H.size();
        H.emplace_back(0);
        int ans = 0;
        stack<pair<int,int>> S;
        
        for (int i = 0; i < n+1; ++i) {
			int prev = i;
			while (S.size() && H[i] < S.top().second) {
                auto [j, h] = S.top(); S.pop();
				ans = max(ans, h * (i - j));
                prev = j;
			}
			S.emplace(prev, H[i]);
        }
        
        return ans;
    }
};