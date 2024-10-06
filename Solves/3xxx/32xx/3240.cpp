class Solution {

private:
    const static int maxn = 2e5 + 2;
    // int F[maxn][4];

public:
    int minFlips(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        // step 1 : calculate each quarter part

        int n1 = n / 2;
        int m1 = m / 2;
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < m1; ++j) {
                int count_one = grid[i][j] + grid[n - i - 1][j] +
                                grid[i][m - j - 1] + grid[n - i - 1][m - j - 1];
                if (count_one > 2)
                    count_one = 4 - count_one;
                ans += count_one;
            }
        }

        // step 2: incase n or m is odd, calculate in center row, col.
        int numOfPalinOnes = 0;
        int numOfChanges = 0;
        if (m % 2 == 1) {
            for (int i = 0; i < n1; ++i) {
                if (grid[i][m1] != grid[n - i - 1][m1]) {
                    ans++;
                    numOfChanges++;
                    continue;
                }
                numOfPalinOnes += grid[i][m1];
            }
        }

        if (n % 2 == 1) {
            for (int j = 0; j < m1; ++j) {
                if (grid[n1][j] != grid[n1][m - j - 1]) {
                    ans++;
                    numOfChanges++;
                    continue;
                }

                numOfPalinOnes += grid[n1][j];
            }
        }
        
        if (numOfPalinOnes % 2 && !numOfChanges)
            ans += 2;
        if (n % 2 & m % 2 && grid[n1][m1])
            ans++;
        return ans;

        return ans;
    }
};