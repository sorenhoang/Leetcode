from typing import List


class Solution:
    def uniquePathsWithObstacles(self, obstacleGrid: List[List[int]]) -> int:
        m = len(obstacleGrid)
        n = len(obstacleGrid[0])

        if obstacleGrid[0][0] + obstacleGrid[m - 1][n - 1] > 0:
            return 0

        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        dp[0][0] = 1

        for i in range(m):
            for j in range(n):
                if obstacleGrid[i][j] == 1:
                    continue
                if i > 0:
                    dp[i][j] += dp[i - 1][j]
                if j > 0:
                    dp[i][j] += dp[i][j - 1]

        ans = dp[m - 1][n - 1]
        print(ans)
        return ans


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.uniquePathsWithObstacles([[0, 0], [0, 0]])
