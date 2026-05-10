class Solution {
    fun chalkReplacer(chalk: IntArray, k: Int): Int {
        val sums = chalk.sumOf{ it.toLong()}

        var rem = k % sums
        for(i in 0..<(chalk.size))
        {
            if(rem<chalk[i]) return i
            rem -= chalk[i]
        }

        return 0
    }
}