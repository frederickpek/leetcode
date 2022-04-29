class Solution(object):
    def plusOne(self, a):
        a.reverse()
        num = 0
        for i, val in enumerate(a):
            num += val * 10**i
        num += 1
        b = []
        while (num > 0):
            b.append(num % 10)
            num //= 10
        b.reverse()
        return b