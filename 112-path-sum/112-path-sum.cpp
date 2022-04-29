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
    bool dfs(TreeNode* root, int sum, int target) {
        sum += root->val;
        if (!root->left && !root->right) return sum == target;
        bool ans = 0;
        if (root->left) ans |= dfs(root->left, sum, target);
        if (root->right) ans |= dfs(root->right, sum, target);
        return ans;
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        return dfs(root, 0, targetSum);
    }
};