from collections import defaultdict
from typing import List


class Solution:
    def minSubarray(self, nums: List[int], div: int) -> int:
        ans = 1e18 + 1
        n = len(nums)
        p = [0] * (n + 1)
        last = defaultdict(int)
        rem = sum(nums) % div

        if rem == 0:
            return 0

        cur = 0

        for i in range(n):
            cur = cur + nums[i]

            if (cur % div) == rem and i != n - 1:
                ans = min(ans, i + 1)

            prev = (cur + div - rem) % div
            if last[prev] != 0:
                ans = min(ans, i - last[prev] + 1)

            last[cur % div] = i + 1

        ans = ans if ans < 1e18 else -1
        print(ans)
        return ans


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.minSubarray(
        [8, 32, 31, 18, 34, 20, 21, 13, 1, 27, 23, 22, 11, 15, 30, 4, 2], 148
    )
