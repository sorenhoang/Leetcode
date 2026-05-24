class Solution {
    fun maxJumps(arr: IntArray, d: Int): Int {
        val n = arr.size
        val dp = IntArray(n, {_ -> -1})

        fun maxJump(index:Int) : Int{
            if(dp[index] != -1) return dp[index]
            val cur = arr[index]
            var max = 0
            for(i in index-1 downTo Math.max(0, index-d))
            {
                if(arr[i] < cur)
                {
                    max = Math.max(max, maxJump(i))
                }
                else break
            }

            for(i in index+1..Math.min(index+d, n-1)){
                if(arr[i]<cur)
                {
                    max = Math.max(max, maxJump(i))
                }
                else break
            }
            dp[index] = 1 + max;
            return dp[index]
        }   

        var max = 0
        for(i in 0..n - 1){
            max = Math.max(max,maxJump(i))
        }
        return max
    }
}