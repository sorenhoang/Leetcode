class Solution:
    def countSubstrings(self, s: str, c: str) -> int:
        countC = s.count(c)

        return countC * (countC+1) // 2
