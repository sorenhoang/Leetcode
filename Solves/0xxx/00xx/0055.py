from typing import List


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        ans = 0

        dp = [1e9] * (n + 1)
        dp[0] = 0
        for i in range(n):
            for j in range(1, nums[i] + 1):
                if i + j == n:
                    return True
                if (i + j) < n:
                    dp[i + j] = min(dp[i + j], dp[i] + 1)
                else:
                    break
        ans = dp[n - 1] < n
        print(ans)
        return ans


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.canJump([3, 2, 1, 0, 4])
