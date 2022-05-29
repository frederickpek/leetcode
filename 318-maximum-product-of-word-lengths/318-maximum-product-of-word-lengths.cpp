class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks;
        for (auto &word : words) {
            int mask = 0;
            for (auto &c : word) mask |= (1<<(c-'a'));
            masks.emplace_back(mask);
        }
        int ans = 0;
        for (int i = 0; i < words.size(); ++i) {
            for (int j = i + 1; j < words.size(); ++j) {
                if (masks[i] & masks[j]) continue;
                ans = max(ans, (int)(words[i].length() * words[j].length()));
            }
        }
        return ans;
    }
};