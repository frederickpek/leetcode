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
    int ans, D;
    
    void dfs(TreeNode* node, int d) {
        if (!node) return;
        if (d == D) ans += node->val;
        if (d > D) { D = d; ans = node->val; }
        dfs(node->left, d + 1);
        dfs(node->right, d + 1);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        ans = 0; D = 0;
        dfs(root, 0);
        return ans;
    }
};