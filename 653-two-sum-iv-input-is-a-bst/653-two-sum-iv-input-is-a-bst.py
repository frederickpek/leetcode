# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def findTarget(self, root: Optional[TreeNode], T: int) -> bool:
        offset = int(1e5) + 5
        cache = [False for _ in range(int(2e5) + 10)]
        def dfs(node):
            if (not node): return False
            if (cache[T - node.val + offset]): return True
            cache[node.val + offset] = True
            return dfs(node.left) or dfs(node.right)
        return dfs(root)