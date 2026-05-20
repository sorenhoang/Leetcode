class Solution {
    fun topKFrequent(nums: IntArray, k: Int): IntArray {
        val map = nums.toList().groupingBy{it}.eachCount()

        val freq = Array<MutableList<Int>>(nums.size + 1) { mutableListOf() } 
        map.forEach{k,v -> freq[v].add(k)}

        return freq.flatMap{ it }.takeLast(k).toIntArray()
    }
}