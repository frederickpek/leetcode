#define rep(i, n) for (int i = 0; i < n; ++i)

map<char,int> M = {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} 
};

class Solution {
public:
    void process(char a, char b, string& s, int& ans, int val) {
        int n = s.length();
        rep(i, n-1) if (s[i] == a && s[i+1] == b) {
            s[i] = '-';
            s[i+1] = '-';
            ans += val;
        }
    }
    
    int romanToInt(string s) {
        int ans = 0;
        process('I', 'V', s, ans, 4);
        process('I', 'X', s, ans, 9);
        process('X', 'L', s, ans, 40);
        process('X', 'C', s, ans, 90);
        process('C', 'D', s, ans, 400);
        process('C', 'M', s, ans, 900);
        for (auto c : s) ans += M[c];
        return ans;
    }
};