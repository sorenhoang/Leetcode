class Solution {
    fun canFinish(numCourses: Int, prerequisites: Array<IntArray>): Boolean {

       // build adjacency matrix
       val graph = Array(numCourses){ mutableListOf<Int>() }
       prerequisites.forEach{ (course, pre) ->
            graph[pre].add(course)
       }

       // States: 0 = unvisited, 1 = visiting, 2 = visited
       val state = IntArray(numCourses)

       fun hasCycles(k:Int): Boolean {
            if(state[k] == 1) return true
            if(state[k] == 2) return false

            state[k] = 1 // mark visiting : only explored in this connected graph but not in all

            // visit all neighbors
            if(graph[k].any{hasCycles(it)}){
                return true
            }

            state[k] = 2 // mark as visited 
            return false
       }

       return (0..<numCourses).none{ hasCycles(it)}


    }
}