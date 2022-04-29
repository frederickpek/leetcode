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
    int fill_height(TreeNode* root) {
        if (!root) return -1;
        root->val = 1 + max(fill_height(root->left), fill_height(root->right));
        return root->val;
    }
    
    bool dfs(TreeNode* root) {
        if (!root) return 1;
        int left_height = root->left ? root->left->val : -1;
        int right_height = root->right ? root->right->val : -1;
        bool balanced = 1;
        balanced &= abs(left_height - right_height) <= 1;
        balanced &= dfs(root->left);
        balanced &= dfs(root->right);
        return balanced;
    }
    
    bool isBalanced(TreeNode* root) {
        fill_height(root);
        return dfs(root);
    }
};