class Solution:
    def sortableIntegers(self, nums: list[int]) -> int:
        n = len(nums)

        def possibleSplit(k: int) -> bool:
            prev_max = 0

            for st in range(0, n, k):
                rotatePoint = -1
                for it in range(st, st + k - 1):
                    if nums[it] > nums[it + 1]:
                        if rotatePoint != -1:
                            return False
                        rotatePoint = it
                if rotatePoint == -1:
                    lo, hi = nums[st], nums[st + k - 1]

                else:
                    if nums[st + k - 1] > nums[st]:
                        return False
                    lo, hi = nums[rotatePoint + 1], nums[rotatePoint]
                if prev_max > lo:
                    return False

                prev_max = hi

            return True

        ans = 0
        for i in range(1, n + 1):
            if n % i == 0 and possibleSplit(i):
                ans += i
        return ans
