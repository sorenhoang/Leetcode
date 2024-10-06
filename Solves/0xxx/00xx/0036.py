from collections import defaultdict
from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        rows = defaultdict(set)
        cols = defaultdict(set)
        boxes = defaultdict(set)

        for i in range(9):
            for j in range(9):
                cur = board[i][j]
                if cur == ".":
                    continue

                if cur in rows[i] or cur in cols[j] or cur in boxes[(i // 3, j // 3)]:
                    return False

                rows[i].add(cur)
                cols[j].add(cur)
                boxes[(i // 3, j // 3)].add(cur)

        return True


if __name__ == "__main__":
    # init
    sol = Solution()
    arr = [
        ["5", "3", ".", ".", "7", ".", ".", ".", "."],
        ["6", ".", ".", "1", "9", "5", ".", ".", "."],
        [".", "9", "8", ".", ".", ".", ".", "6", "."],
        ["8", ".", ".", ".", "6", ".", ".", ".", "3"],
        ["4", ".", ".", "8", ".", "3", ".", ".", "1"],
        ["7", ".", ".", ".", "2", ".", ".", ".", "6"],
        [".", "6", ".", ".", ".", ".", "2", "8", "."],
        [".", ".", ".", "4", "1", "9", ".", ".", "5"],
        [".", ".", ".", ".", "8", ".", ".", "7", "9"],
    ]
    # act

    print(sol.isValidSudoku(arr))
