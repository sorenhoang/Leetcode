from collections import defaultdict
from typing import List


class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def backtrack(start, target, path):
            if target == 0:
                result.append(path)
                return
            if target < 0:
                return
            for i in range(start + 1, len(candidates)):
                backtrack(i, target - candidates[i], path + [candidates[i]])

        result = []
        candidates.sort()
        print(candidates)
        backtrack(0, target, [])
        
        return result


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    print(sol.combinationSum2([10, 1, 2, 7, 6, 1, 5], 8))
