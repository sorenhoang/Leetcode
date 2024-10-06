class Solution:
    def simplifyPath(self, path: str) -> str:
        p = [""] * 3000
        curStack = 0
        lst = path.split("/")
        for item in lst:
            if item == "" or item == ".":
                continue
            if item == "..":
                curStack = max(0, curStack - 1)
                continue
            p[curStack] = item
            curStack += 1

        ans = "/" + "/".join(p[0:curStack])

        print(ans)
        return ans


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.simplifyPath("/../")
