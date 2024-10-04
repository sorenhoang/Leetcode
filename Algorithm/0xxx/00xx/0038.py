class Solution:
    def countAndSay(self, n: int) -> str:

        def count_til_diff(s: str):
            res = ""
            i = 0
            temp = ""
            while i < len(s):
                count = 1
                check = s[i]
                if check == temp:
                    break
                temp = check
                for j in range(i + 1, len(s)):
                    if s[j] != check:
                        i = j
                        break

                    count += 1

                    if j == len(s) - 1:
                        i = j
                        break
                res += str(count) + check
            return res

        if n == 1:
            return "1"
        return count_til_diff(self.countAndSay(n - 1))


if __name__ == "__main__":
    # init
    sol = Solution()
    print(sol.countAndSay(4))
