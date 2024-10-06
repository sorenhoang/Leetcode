from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        curMin = 0
        ans = -1e9
        curSum = 0
        for i in range(len(nums)):
            curSum += nums[i]
            ans = max(ans, curSum - curMin)
            curMin = min(curMin, curSum)
        print(ans)
        return ans


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.maxSubArray([-2, 1, -3, 4, -1, 2, 1, -5, 4])
