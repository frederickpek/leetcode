class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        strs = sorted(list(map(lambda s: ("".join(sorted([c for c in s])), s), strs)))
        ans = []
        prev = "?"
        for curr, s in strs:
            if prev != curr:
                ans.append([])
            ans[-1].append(s)
            prev = curr
        return ans
    