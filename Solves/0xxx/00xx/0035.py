from typing import List


class Solution:
    def searchInsert(self, nums: List[int], target: int) -> int:
        def bs(nums, t: int, l: int, r: int) -> int:
            if r - l > 1:
                mid = (l + r) // 2
                if nums[mid] > t:
                    return bs(nums, t, l, mid)
                else:
                    return bs(nums, t, mid, r)
            else:
                return l

        id = bs(nums, target, 0, len(nums))

        return id if nums[id] >= target else id + 1


if __name__ == "__main__":
    # init
    sol = Solution()

    print(sol.searchInsert([1, 3, 5, 6], 5))
