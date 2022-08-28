class Solution:
    def diagonalSort(self, mat: List[List[int]]) -> List[List[int]]:
        n, m, rows = len(mat), len(mat[0]), list()
        
        i0, j0 = 0, m - 1
        while (i0 < n):
            i = i0
            j = max(j0, 0)
            rows.append(list())
            while (i < n and j < m):
                rows[-1].append(mat[i][j])
                i += 1
                j += 1
            rows[-1].sort()
            j0 -= 1
            i0 += 1 if j0 < 0 else 0
        
        i0, j0, k = 0, m - 1, 0
        while (i0 < n):
            i = i0
            j = max(j0, 0)
            for val in rows[k]:
                mat[i][j] = val
                i += 1
                j += 1
            j0 -= 1
            i0 += 1 if j0 < 0 else 0
            k += 1
            
        return mat
    