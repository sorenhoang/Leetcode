from typing import List


class Solution:
    def dividePlayers(self, skills: List[int]) -> int:
        ans = 0
        sums = sum(skills)
        n = len(skills)
        skills.sort()

        if ((sums * 2) % n) != 0:
            return -1

        sums = sums * 2 // n

        for i in range(n):
            if skills[i] + skills[n - i - 1] != sums:
                return -1
            ans += skills[i] * skills[n - i - 1]

        ans //= 2

        print(ans)
        return ans


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.dividePlayers([3, 2, 5, 1, 3, 4])
