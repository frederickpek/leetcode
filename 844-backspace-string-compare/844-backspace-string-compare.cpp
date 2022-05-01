class Solution {
public:
    string process(string& s) {
        string ret = "";
        for (auto c : s) {
            if (c != '#') {
                ret.push_back(c);
                continue;
            }
            if (!ret.length()) continue;
            ret.pop_back();
        }
        return ret;
    }
    
    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
};