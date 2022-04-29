#define rep(i, n) for (int i = 0; i < n; ++i)
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") return 0;
        return haystack.find(needle);
    }
};