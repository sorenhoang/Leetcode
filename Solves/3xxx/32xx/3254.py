class Solution:
    def resultsArray(self, nums: List[int], k: int) -> List[int]:
        if k == 1:
            return nums
        ans = []
        curSec = 1

        for i in range(1, len(nums)):
            if nums[i] == nums[i-1] + 1:
                curSec += 1
            else:
                curSec = 1
            if i >= k-1:
                ans.append(nums[i] if curSec >= k else -1)

        return ans
