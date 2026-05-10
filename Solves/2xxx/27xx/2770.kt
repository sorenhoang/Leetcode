import kotlin.math.abs

class Solution {
    fun maximumJumps(nums: IntArray, target: Int): Int {
        val n = nums.size
        
        val dp = IntArray( n+1 ) { -1 }

        dp[1] = 0

        for(i in 1..n)
        {
            for(j in 1..<i)
            {
                if(abs(nums[i-1] - nums[j-1]) <= target && dp[j] != -1)
                {
                    dp[i] = maxOf(dp[i], dp[j] + 1)
                }
            }
        }

        return dp[n]
    }
}