class Solution:
    def minDistance(self, word1: str, word2: str) -> int:
        # dynamic programming, bottom up
        cache = [[float("inf")] * (len(word2) + 1) for _ in range(len(word1) + 1)]
        # fill in the bottom row
        for col in range(len(word2) + 1):
            cache[len(word1)][col] = len(word2) - col  # base case when word 1 is empty
        # fill in the last column
        for row in range(len(word1) + 1):
            cache[row][len(word2)] = len(word1) - row  # base case when word 2 is empty
        for i in range(len(word1) - 1, -1, -1):
            for j in range(len(word2) - 1, -1, -1):
                if word1[i] == word2[j]:  # char is equal
                    cache[i][j] = cache[i + 1][j + 1]
                else:  # char is not equal
                    cache[i][j] = (
                        min(cache[i + 1][j], cache[i][j + 1], cache[i + 1][j + 1]) + 1
                    )  # check insert, delete, replace, all there directions in the 2d cache array
        print(cache[0][0])
        return cache[0][0]


if __name__ == "__main__":
    # init
    sol = Solution()
    # act
    sol.minDistance("horse", "ros")
