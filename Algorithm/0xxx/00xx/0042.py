from typing import List


class Solution:
    def trap(self, height: List[int]) -> int:
        ans = 0
        n = len(height)
        col = [[0 for _ in range(2)] for _ in range(n)]

        for i in range(n):
            col[i] = [height[i], i]

        col.sort(key=lambda x: x[0], reverse=True)

        l = n
        r = -1
        top = 1e9
        hasCol = 0

        i = 0
        while i < n:
            if l != n and r != -1:
                ans += (top - col[i][0]) * (r - l + 1 - hasCol)
            id = i
            while id < n and col[id][0] == col[i][0]:
                hasCol += 1
                l = min(l, col[id][1])
                r = max(r, col[id][1])
                id += 1

            top = col[i][0]
            i = id

        print(ans)

        return ans


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.trap([4, 2, 0, 3, 2, 5])
