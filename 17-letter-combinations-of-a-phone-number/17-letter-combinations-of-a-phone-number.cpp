class Solution {
public:
    string S;
    vector<string> ret;
    map<int,string> M = {
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    void dfs(string &digits, int i, string s) {
        if (i == digits.length()) {
            ret.emplace_back(s);
            return;
        }
        for (auto c : M[digits[i]])
            dfs(digits, i+1, s+c);
    }
    
    vector<string> letterCombinations(string digits) {
        ret.clear();
        if (digits.length()) dfs(digits, 0, "");
        return ret;
    }
};