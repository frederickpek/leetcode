/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> ans;
    
    void dfs(TreeNode* u, int depth) {
        if (!u) return;
        if (ans.size() <= depth) ans.push_back(0);
        ans[depth] = u->val;
        dfs(u->left, depth + 1);
        dfs(u->right, depth + 1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};