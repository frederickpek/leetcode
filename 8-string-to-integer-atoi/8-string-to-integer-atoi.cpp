class Solution {
public:
    int myAtoi(string s) {
        int i = 0;
        int n = s.length();
        while (s[i] == ' ' && i < n) i++;
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+') {
            sign = 1;
            i++;
        }
        
        long long sum = 0;
        long long lb = -(1L<<31);
        long long ub = (1L<<31) - 1;
        while (s[i] >= '0' && s[i] <= '9' && i < n) {
            sum *= 10;
            sum += (s[i]-'0');
            if (sum * sign > ub) return ub;
            if (sum * sign < lb) return lb;
            ++i;
        }
        return sign * sum;
    }
};