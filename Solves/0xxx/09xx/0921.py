class Solution:
    def minAddToMakeValid(self, s: str) -> int:
        ans = 0
        cur = 0
        for c in s:
            cur += 1 if c == "(" else -1
            ans = min(ans, cur)

        ans = -ans * 2 + cur
        return ans


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    print(sol.minAddToMakeValid("()))(("))
