from typing import List

class Solution:
    def rotate(self, matrix: List[List[int]]) -> None:
        edgeLength = len(matrix)
        top = 0
        bottom = edgeLength - 1
        while top < bottom:
            for col in range(edgeLength):
                matrix[top][col], matrix[bottom][col] = matrix[bottom][col], matrix[top][col]
            top += 1
            bottom -= 1
        for row in range(edgeLength):
            for col in range(row + 1, edgeLength):
                matrix[row][col], matrix[col][row] = matrix[col][row], matrix[row][col]


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.rotate([[5, 1, 9, 11], [2, 4, 8, 10], [13, 3, 6, 7], [15, 14, 12, 16]])
