from typing import List


class Solution:
    def sortColors(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        count = [0] * 3
        for num in nums:
            count[num] += 1
        for i in range(1, 3):
            count[i] += count[i - 1]
        for i in range(len(nums)):
            for j in range(2, -1, -1):
                if i < count[j]:
                    nums[i] = j
        print(nums)


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    print(sol.sortColors([2, 0, 2, 1, 1, 0]))
