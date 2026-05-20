class Solution {
    fun countNicePairs(nums: IntArray): Int {
        val subMaps = mutableMapOf<Int, Int>()

        for(num in nums)
        {
            val sub = getSub(num)
            
            val countSub = subMaps.getOrDefault(sub, 0)
            subMaps[sub] = countSub + 1
        }

        var sum: Long = 0
        val mod = 1e9.toInt() + 7

        for ((key, value) in subMaps) 
        {
            sum = (sum + value.toLong() * (value-1) / 2) % mod
        }
        
        return sum.toInt()
    }

    fun getSub(num : Int): Int{
        var res = 0
        
        var x = num
        while(x > 0)
        {
            res = res * 10 + x % 10
            x /= 10
        }

        return res - num
    }
}