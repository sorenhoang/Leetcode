package main

import "fmt"

func pacificAtlantic(heights [][]int) [][]int {

	// check each of the nodes for 2 flags - pacific and atlantic
	// the 2 flags are achievable if the control reaches the top-left or bottom-right boundry
	// BFS over each cell, we need to have a visted array in place so that we do not check the visited cells again in an iteration
	// To avoid TLE we need to have memoisation in place so that if from cell (x,y) we can reach atlantic and pacific oceans then all the controls reaching (x,y) must be reaching the 2 oceans
	// Remember - to only put the cells in queue that are lesser than the current cell value

	var q [][]int
	// try with 1d array!
	var visited, reachable [][]bool
	result := make([][]int, 0)

	for k := 0; k < len(heights); k++ {
		reachable = append(reachable, make([]bool, len(heights[k])))
	}

	for i := 0; i < len(heights); i++ {

		for j := 0; j < len(heights[i]); j++ {

			q = make([][]int, 0)
			q = append(q, []int{i, j})

			visited = make([][]bool, 0)
			for k := 0; k < len(heights); k++ {
				visited = append(visited, make([]bool, len(heights[k])))
			}

			if bfs(heights, q, visited, reachable) {
				reachable[i][j] = true
				result = append(result, []int{i, j})
			}
		}
	}

	return result
}

func bfs(heights, q [][]int, visited, reachable [][]bool) bool {
	var p, a bool // default false
	var x, y int

	for len(q) > 0 {
		// popped the top element
		x = q[0][0]
		y = q[0][1]
		q = q[1:]

		visited[x][y] = true

		if reachable[x][y] {
			return true
		}

		if x-1 < 0 || y-1 < 0 {
			p = true
		}

		if x+1 == len(heights) || y+1 == len(heights[x]) {
			a = true
		}

		if p && a {
			return true
		}

		// add the nodes to the queue if they are adhere to boundry cases
		if x-1 >= 0 && !visited[x-1][y] && heights[x-1][y] <= heights[x][y] {
			q = append(q, []int{x - 1, y})
		}

		if y-1 >= 0 && !visited[x][y-1] && heights[x][y-1] <= heights[x][y] {
			q = append(q, []int{x, y - 1})
		}

		if x+1 < len(heights) && !visited[x+1][y] && heights[x+1][y] <= heights[x][y] {
			q = append(q, []int{x + 1, y})
		}

		if y+1 < len(heights[x]) && !visited[x][y+1] && heights[x][y+1] <= heights[x][y] {
			q = append(q, []int{x, y + 1})
		}
	}

	return false
}

func main() {
	heights1 := [][]int{
		{1, 2, 2, 3, 5},
		{3, 2, 3, 4, 4},
		{2, 4, 5, 3, 1},
		{6, 7, 1, 4, 5},
		{5, 1, 1, 2, 4},
	}
	heights2 := [][]int{
		{1},
	}

	fmt.Println("Output for heights1:", pacificAtlantic(heights1))
	fmt.Println("Output for heights2:", pacificAtlantic(heights2))
}
