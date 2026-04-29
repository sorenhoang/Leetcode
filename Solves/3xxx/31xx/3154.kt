class Solution {
    private val dp = mutableMapOf<Triple<Int, Int, Boolean>, Int>()

    fun waysToReachStair(k: Int): Int {
        fun backtrack(stair: Int, jump: Int, lastDown: Boolean): Int {
            if (stair !in 0..k + 1) return 0
            return dp.getOrPut(Triple(stair, jump, lastDown)) {
                var res = if (stair == k) 1 else 0
                if (!lastDown) res += backtrack(stair - 1, jump, !lastDown)
                res += backtrack(stair + (1 shl jump), jump + 1, false)
                res
            }
        }
        return backtrack(1, 0, false)
    }
}