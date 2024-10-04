from collections import defaultdict
from typing import List


class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        def origin(str):
            cnt = [0] * 26
            for c in str:
                cnt[ord(c) - ord("a")] += 1
            tmp = ""
            for i in range(26):
                if cnt[i] > 0:
                    tmp += chr(i + ord("a")) * cnt[i]
            return tmp
            pass

        dict = defaultdict(list)
        for str in strs:
            dict[origin(str)].append(str)

        result = []
        for key in dict:
            result.append(dict[key])

        print(result)
        return result


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
