class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:

        n = len(s1)
        m = len(s2)
        count_s1 = [0] * 26
        count_s2 = [0] * 26

        for c in s1:
            count_s1[ord(c) - ord("a")] += 1

        for i in range(len(s2)):
            c = s2[i]

            count_s2[ord(c) - ord("a")] += 1

            if i >= n:
                p = s2[i - n]
                count_s2[ord(p) - ord("a")] -= 1

            if i >= n - 1:
                ok = True
                for id in range(26):
                    ok = ok and count_s1[id] == count_s2[id]
                if ok == True:
                    return True

        return False


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    print(sol.checkInclusion("ab", "eidbaooo"))
