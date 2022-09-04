# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def verticalTraversal(self, root: Optional[TreeNode]) -> List[List[int]]:
        d = defaultdict(list)
        def dfs(u, i, j):
            if (not u): return
            d[j].append((j, i, u.val))
            dfs(u.left, i+1, j-1)
            dfs(u.right, i+1, j+1)
        dfs(root, 0, 0)
        return list(map(lambda l: list(map(lambda x: x[2], sorted(l, key=lambda e: (e[1], e[2])))), sorted([v for k, v in d.items()])))
    