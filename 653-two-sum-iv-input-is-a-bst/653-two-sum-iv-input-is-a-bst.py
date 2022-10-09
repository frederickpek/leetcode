# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], T: int) -> bool:
        cache = set()
        def dfs(node):
            if (not node): return False
            if (T - node.val in cache): return True
            cache.add(node.val)
            return dfs(node.left) or dfs(node.right)
        return dfs(root)