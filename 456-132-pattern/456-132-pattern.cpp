class Solution {
public:
    bool find132pattern(vector<int>& a) {
        int n = a.size();
        vector<int> mn(n);
        for (int i = 0; i < n; i++) mn[i] =  i ? min(mn[i - 1], a[i]) : a[0];
        stack<int> S;
        for (int i = n-1; i >= 0; --i) {
            if (mn[i] < a[i]) {
                while (S.size() && S.top() <= mn[i]) S.pop();
                if (S.size() && S.top() < a[i]) return 1;
                S.push(a[i]);
            }
        }
        return 0;
    }
};