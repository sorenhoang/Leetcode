from typing import List


class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort(key=lambda x: x[0])
        n = len(intervals)
        i = 0
        res = []

        while i < n:
            l = intervals[i][0]
            r = intervals[i][1]
            id = i
            while id < n and intervals[id][0] <= r:
                r = max(r, intervals[id][1])
                id += 1
            res.append([l, r])
            i = id

        print(res)
        return res


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.merge([[1, 3], [2, 6], [8, 10], [15, 18]])
