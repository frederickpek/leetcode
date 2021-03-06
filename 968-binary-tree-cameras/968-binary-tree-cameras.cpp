class Solution {
public:
    int ans = 0;
    
    int dfs(TreeNode* root) {
        if (!root) return 2;
        int left = dfs(root->left), right = dfs(root->right);
        if (left == 0 || right == 0) {
            ans++;
            return 1;
        }
        return left == 1 || right == 1 ? 2 : 0;
    }
    
    int minCameraCover(TreeNode* root) {
        return (dfs(root) < 1 ? 1 : 0) + ans;
    }
};
