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
    TreeNode* bst(vector<int>& nums, int i, int j) {
        if (i > j) return nullptr;
        int mid = (i + j) / 2;
        TreeNode* left = bst(nums, i, mid-1);
        TreeNode* right = bst(nums, mid+1, j);
        return new TreeNode(nums[mid], left, right);
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = (int)nums.size();
        return bst(nums, 0, n-1);
    }
};