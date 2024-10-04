class Solution:
    def isMatch(self, p: str, s: str) -> bool:
        n = len(s)
        m = len(p)
        s = " " + s
        p = " " + p

        dp = [[False for _ in range(m + 1)] for _ in range(n + 1)]
        dp[0][0] = True

        for i in range(1, n + 1):
            if s[i] == "*":
                dp[i][0] = dp[i - 1][0]
            else:
                dp[i][0] = False
            this_col_ok = dp[i - 1][0]
            for j in range(1, m + 1):
                if s[i] != "?" and s[i] != "*":
                    dp[i][j] = dp[i - 1][j - 1] and s[i] == p[j]
                elif s[i] == "?":
                    dp[i][j] = dp[i - 1][j - 1]
                else:
                    this_col_ok = this_col_ok or dp[i - 1][j]
                    dp[i][j] = this_col_ok
        print(dp[n][m])

        return dp[n][m]


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.isMatch("adceb", "*a*b")
