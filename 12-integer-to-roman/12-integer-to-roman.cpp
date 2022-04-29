class Solution {
public:
    map<int,string> M = {
        {1, "I"}, {2, "II"}, {3, "III"}, {4, "IV"}, {5, "V"}, {6, "VI"}, {7, "VII"}, {8, "VIII"}, {9, "IX"},
        {10, "X"}, {20, "XX"}, {30, "XXX"}, {40, "XL"}, {50, "L"}, {60, "LX"}, {70, "LXX"}, {80, "LXXX"}, {90, "XC"},
        {100, "C"}, {200, "CC"}, {300, "CCC"}, {400, "CD"}, {500, "D"}, {600, "DC"}, {700, "DCC"}, {800, "DCCC"}, {900, "CM"},
        {1000, "M"}, {2000, "MM"}, {3000, "MMM"}
    };
    
    string intToRoman(int num) {
        vector<string> sol;
        int ten = 1;
        while (num) {
            int val = num % 10;
            num /= 10;
            sol.emplace_back(M[val * ten]);
            ten *= 10;
        }
        reverse(sol.begin(), sol.end());
        string ans = "";
        for (auto s : sol) ans += s;
        return ans;
    }
};