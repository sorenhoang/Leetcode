from typing import List


class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])

        dp = [[1e9 for _ in range(n + 1)] for _ in range(m + 1)]
        dp[0][0] = 0

        for i in range(m):
            for j in range(n):
                if i > 0:
                    dp[i][j] = min(dp[i][j], dp[i - 1][j])
                if j > 0:
                    dp[i][j] = min(dp[i][j], dp[i][j - 1])

                dp[i][j] += grid[i][j]

        ans = dp[m - 1][n - 1]
        print(ans)
        return ans


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.minPathSum([[1, 3, 1], [1, 5, 1], [4, 2, 1]])
