class TrieNode{
    val children = mutableMapOf<Char, TrieNode>()
}

internal class Trie{
    private val root = TrieNode()
    
    fun addNum(num : String)
    {
        var currentNode = root
        for(c in num)
        {
            if(!currentNode.children.containsKey(c))
            {
                currentNode.children[c] = TrieNode()
            }

            currentNode = currentNode.children[c]!!
        }
    }

    fun getPrefixSize(num: String): Int{
        var ans = 0

        var currentNode = root
        for(c in num)
        {
            if(!currentNode.children.containsKey(c)) break;
            currentNode = currentNode.children[c]!!;
            ans ++
        }

        return ans
    }
}

class Solution {
    fun longestCommonPrefix(arr1: IntArray, arr2: IntArray): Int {
        val trie = Trie()
        var res = 0
        
        for(num in arr1) {
            val numString = num.toString()
            trie.addNum(numString)
        }

        for(num in arr2) {
            val numString = num.toString()
            res = maxOf(res, trie.getPrefixSize(numString))
        }
        
        return res
    }
}