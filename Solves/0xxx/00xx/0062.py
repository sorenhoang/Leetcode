class Solution:
    # return C(n-1, n + m-2 )
    def uniquePaths(self, m: int, n: int) -> int:
        ans = 1
        n -= 1
        m -= 1
        sum = n + m
        if n > m:
            n, m = m, n
        for i in range(n):
            ans *= sum - i

        for i in range(n):
            ans //= i + 1
        print(ans)
        return ans


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.uniquePaths(3, 2)
