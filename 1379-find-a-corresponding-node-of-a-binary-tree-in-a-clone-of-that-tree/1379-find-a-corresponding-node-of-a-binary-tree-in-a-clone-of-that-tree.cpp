/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* dfs(TreeNode* u, int t) {
        if (!u) return u;
        if (u->val == t) return u;
        TreeNode* left = dfs(u->left, t);
        TreeNode* right = dfs(u->right, t);
        return left ? left : right;
    }
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return dfs(cloned, target->val);
    }
};