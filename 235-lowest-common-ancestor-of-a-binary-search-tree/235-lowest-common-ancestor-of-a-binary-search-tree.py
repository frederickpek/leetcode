# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, u: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if (p.val < u.val and q.val < u.val):
            return self.lowestCommonAncestor(u.left, p, q)
        if (p.val > u.val and q.val > u.val):
            return self.lowestCommonAncestor(u.right, p, q)
        return u