class Solution {
    fun findThePrefixCommonArray(A: IntArray, B: IntArray): IntArray {
        val n = A.size
        val freq = IntArray(n)
        val res = IntArray(n)
        
        var cur = 0

        for(i in 0..<n)
        {
            val a = A[i]-1
            val b = B[i]-1
            freq[a] += 1
            freq[b] += 1

            if(freq[a] == 2) cur += 1
            if(freq[b] == 2) 
            {
                cur += 1;
                if(a == b) cur -= 1
            }

            res[i] = cur
        }

        return res
    }
}