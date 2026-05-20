class Solution {
    
    fun calculate(s: String): Int {
        var acc = 0        
        var i = 0
        
        val signStack = LinkedList<Int>()  
        var parenSigns = 1
        var prevSign = 1
        
        while (i < s.length) {
            val c = s[i]
            when(c) {
                ' ' -> {}
                '(' -> { 
                    signStack.push(prevSign)
                    if (prevSign < 0) parenSigns *= -1
                    prevSign = 1
                }
                ')' -> if (signStack.pop() < 0) parenSigns *= -1
                '+' ->  prevSign = 1
                '-' -> prevSign = -1
                else -> { // parse whole number
                    var n = 0
                    while(i < s.length && '0' <= s[i] && s[i] <= '9') {
                        n = n * 10 + (s[i] - '0')
                        i++
                    }
                    i--
                    acc += n * parenSigns * prevSign
                }
            }
            i++
        }
     
        return acc
    }
}