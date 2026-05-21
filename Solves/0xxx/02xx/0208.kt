internal class TrieNode {
    val children = mutableMapOf<Char, TrieNode>()
    var isEnd = false
}

class Trie() {
    private val root = TrieNode()

    fun insert(word: String) {
        var node = root
        for(c in word)
        {
            node = node.children.getOrPut(c) {TrieNode()}
        }
        node.isEnd = true
    }

    fun search(word: String): Boolean {
        val node = findNode(word)
        return node != null && node.isEnd
    }

    fun startsWith(prefix: String): Boolean {
        return findNode(prefix) != null
    }

    private fun findNode(prefix: String): TrieNode? {
        var node = root
        for (c in prefix) {
            node = node.children[c] ?: return null
        }
        return node
    }

}

/**
 * Your Trie object will be instantiated and called as such:
 * var obj = Trie()
 * obj.insert(word)
 * var param_2 = obj.search(word)
 * var param_3 = obj.startsWith(prefix)
 */