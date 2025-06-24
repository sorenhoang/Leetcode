package l77

// Leetcode 77: Combinations

import (
	"fmt"
)

func combine(n int, k int) [][]int {
	var res [][]int
	var path []int
	var dfs func(start int)
	dfs = func(start int) {
		if len(path) == k {
			tmp := make([]int, k)
			copy(tmp, path)
			res = append(res, tmp)
			return
		}
		for i := start; i <= n; i++ {
			path = append(path, i)
			dfs(i + 1)
			path = path[:len(path)-1]
		}
	}
	dfs(1)
	return res
}

func main() {
	n, k := 4, 2
	result := combine(n, k)
	fmt.Println(result)
}
