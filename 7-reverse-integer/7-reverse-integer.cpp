class Solution {
public:
    int reverse(int x) {
        string y = to_string(abs(x));
        ::reverse(y.begin(), y.end());
        int sign = x < 0 ? -1 : 1;
        
        if (y.length() > 10) return 0;
        if (y.length() < 10) return sign * stoi(y);
        if (sign == -1) return (y <= "2147483648") ? -stoi(y) : 0;
        return (y <= "2147483647") ? stoi(y): 0;
    }
};