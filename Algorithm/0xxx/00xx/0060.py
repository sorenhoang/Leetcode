class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        ans = ""
        k -= 1
        f = [0] * n
        f[0] = 1
        for i in range(1, n):
            f[i] = f[i - 1] * i

        visit = [0] * n

        for id in range(n - 1, -1, -1):
            cur = 0
            while k >= f[id]:
                cur += 1
                k -= f[id]
            for i in range(n):
                if visit[i] == 1:
                    continue

                if cur == 0:
                    ans += str(i + 1)
                    visit[i] = 1
                    break
                else:
                    cur -= 1

        print(ans)
        return ans


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.getPermutation(3, 1)
