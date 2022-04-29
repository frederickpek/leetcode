class Solution {
public:
    bool isValid(string s) {
        stack<char> q;
        for (char c : s) {
            if (q.empty()) {
                q.push(c);
                continue;
            }
            if (c == ')') {
                if (q.top() == '(') q.pop();
                else return 0;
                continue;
            }
            if (c == '}') {
                if (q.top() == '{') q.pop();
                else return 0;
                continue;
            }
            if (c == ']') {
                if (q.top() == '[') q.pop();
                else return 0;
                continue;
            }
            q.push(c);
        }
        return q.empty();
    }
};