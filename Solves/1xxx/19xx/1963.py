class Solution:
    def minSwaps(self, s: str) -> int:
        p = 0
        for c in s:
            p = max(0, p + (c == "[") - (c == "]"))
        return (p + 1) // 2
