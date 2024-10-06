from typing import List


class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        n = len(matrix)
        m = len(matrix[0])

        def getIndex(self, id):
            return id // m, id % m

        l = 0
        r = n * m
        while r - l > 1:
            mid = (l + r) // 2
            x, y = getIndex(self, mid)

            if matrix[x][y] > target:
                r = mid
            else:
                l = mid

        x, y = getIndex(self, l)
        print(l, x, y)
        return matrix[x][y] == target


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    print(sol.searchMatrix([[1, 3, 5, 7], [10, 11, 16, 20], [23, 30, 34, 60]], 3))
