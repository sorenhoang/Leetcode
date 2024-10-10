from typing import List


class Solution:
    def maxWidthRamp(self, nums: List[int]) -> int:
        ans = 0

        st = []

        n = len(nums)

        for i in range(n):
            if not st or nums[st[-1]] > nums[i]:
                st.append(i)

        for i in range(n - 1, -1, -1):
            while st and nums[i] >= nums[st[-1]]:
                ans = max(ans, i - st.pop())

        return ans


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    print(sol.maxWidthRamp([6, 0, 8, 2, 1, 5]))
