class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(), products.end());
        vector<vector<string>> res;
        
        string curr = "";
        auto it = products.begin();
        for (auto c : searchWord) {
            curr.push_back(c);
            vector<string> ans;
            it = lower_bound(it, products.end(), curr);
            for(int len = 0; len < 3; ++len) {
                if (it + len == products.end()) break;
                string& n = *(it + len);
                if (curr != n.substr(0, curr.size())) break;
                ans.push_back(n);
            }
            res.push_back(ans);
        }
        
        return res;
    }
};