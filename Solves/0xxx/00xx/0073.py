from typing import List


class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        n = len(matrix)
        m = len(matrix[0])
        cols = [0] * m
        rows = [0] * n

        for i in range(n):
            for j in range(m):
                if matrix[i][j] == 0:
                    cols[j] = 1
                    rows[i] = 1

        for i in range(n):
            for j in range(m):
                if cols[j] or rows[i]:
                    matrix[i][j] = 0

        print(matrix)

        """
        Do not return anything, modify matrix in-place instead.
        """


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.setZeroes([[1, 1, 1], [1, 0, 1], [1, 1, 1]])
