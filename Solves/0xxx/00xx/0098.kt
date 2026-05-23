class Solution {
    fun isValidBST(root: TreeNode?): Boolean = isValidBSTInternal(root)

    private fun isValidBSTInternal(
        root: TreeNode?,
        min: Long = Long.MIN_VALUE,
        max: Long = Long.MAX_VALUE,
    ): Boolean {
        if (root == null) return true
        if (root.`val` !in min..max) return false
        return isValidBSTInternal(root.left, min, root.`val`.toLong() - 1)
            && isValidBSTInternal(root.right, root.`val`.toLong() + 1, max)
    }
}