#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int MOD = 1e9 + 7;

public:
    int dieSimulator(int n, vector<int> &rollMax)
    {
        // dp[i][j][k] = số cách tại vị trí i, mặt cuối cùng là j, đã liên tiếp k lần
        // i: vị trí (0 đến n-1)
        // j: mặt xúc xắc (0-5 tương ứng 1-6)
        // k: số lần liên tiếp (1 đến rollMax[j])
        
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(6, vector<long long>(16, 0)));
        
        // Base case: lần đầu tiên, mỗi mặt xuất hiện 1 lần
        for (int j = 0; j < 6; j++)
        {
            dp[1][j][1] = 1;
        }
        
        // Fill DP table
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < 6; j++)  // Mặt hiện tại
            {
                for (int prev = 0; prev < 6; prev++)  // Mặt trước đó
                {
                    if (j == prev)
                    {
                        // Nếu cùng mặt, tăng số lần liên tiếp
                        for (int k = 1; k < rollMax[j]; k++)
                        {
                            dp[i][j][k + 1] = (dp[i][j][k + 1] + dp[i - 1][prev][k]) % MOD;
                        }
                    }
                    else
                    {
                        // Nếu khác mặt, reset số lần liên tiếp về 1
                        for (int k = 1; k <= rollMax[prev]; k++)
                        {
                            dp[i][j][1] = (dp[i][j][1] + dp[i - 1][prev][k]) % MOD;
                        }
                    }
                }
            }
        }
        
        // Tính tổng kết quả
        long long res = 0;
        for (int j = 0; j < 6; j++)
        {
            for (int k = 1; k <= rollMax[j]; k++)
            {
                res = (res + dp[n][j][k]) % MOD;
            }
        }
        
        return res;
    }
};

int main()
{
    // Input: n = 3, rollMax = [1,1,1,2,2,3]
    vector<int> rollMax = {1, 1, 1, 2, 2, 3};
    cout << Solution().dieSimulator(3, rollMax) << endl;
    return 0;
}