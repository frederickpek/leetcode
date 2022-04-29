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
    void invert(TreeNode* root) {
        if (!root) return;
        swap(root->left, root->right);
        invert(root->left);
        invert(root->right);
    }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q) return 1;
        else if (!p || !q) return 0;
        bool same = 1;
        same &= p->val == q->val;
        same &= isSameTree(p->left, q->left);
        same &= isSameTree(p->right, q->right);
        return same;
    }
    
    bool isSymmetric(TreeNode* root) {
        invert(root->right);
        return isSameTree(root->left, root->right);
    }
};