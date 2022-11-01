class Solution:
    def findBall(self, G: List[List[int]]) -> List[int]:
        n, m = len(G), len(G[0])
        ans = [-1 for j in range(m)]
        
        UP, LEFT, RIGHT, STUCK = 69, 420, 9001, 1e9 + 7
        dir = {
            UP: {1: (LEFT, 0, 1), -1: (RIGHT, 0, -1)},
            LEFT: {1: (UP, 1, 0), -1: (STUCK, -1, -1)},
            RIGHT: {1: (STUCK, -1, -1), -1: (UP, 1, 0)},
        }
        
        for _j in range(m):
            i = 0
            j = _j
            prev = UP
            while (True):
                curr, di, dj = dir[prev][G[i][j]]
                if (curr == STUCK): break
                i, j = i + di, j + dj
                if (j < 0 or j > m - 1): break
                if (i > n - 1):
                    ans[_j] = j
                    break
                prev = curr
        
        return ans