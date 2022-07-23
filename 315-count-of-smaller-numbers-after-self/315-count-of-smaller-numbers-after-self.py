_offset: int = 1e4 + 7

class FenwickTree:
    def __init__(self):
        self.ft = defaultdict(int)
        
    def lsone(self, s: int):
        return int(s) & int(-s)
        
    def rsq(self, i: int, j: int):
        if i > 1:
            return self.rsq(1, j) - self.rsq(1, i - 1)
        sum = 0
        while j > 0:
            sum += self.ft[j]
            j -= self.lsone(j)
        return sum

    def update(self, i: int, v: int):
        while i < (2 * _offset):
            self.ft[i] += v
            i += self.lsone(i)
    
class Solution:
    def countSmaller(self, nums: List[int]) -> List[int]:
        nums = list(map(lambda x: x + _offset, nums))
        ret = [0] * len(nums)
        FT = FenwickTree()
        for i in range(len(nums)):
            j = len(nums) - 1 - i
            ret[j] = FT.rsq(0, nums[j] - 1)
            FT.update(nums[j], 1)
        return ret