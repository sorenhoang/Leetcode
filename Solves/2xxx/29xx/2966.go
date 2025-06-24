package main

import (
	"fmt"
	"sort"
)

func divideArray(nums []int, k int) [][]int {
	sort.Ints(nums)
	res := make([][]int, 0)
	for i := 0; i < len(nums); i += 3 {
		a, b, c := nums[i], nums[i+1], nums[i+2]
		if (c - a) > k {
			return [][]int{}
		}
		res = append(res, []int{a, b, c})
	}
	return res
}

func main() {

	fmt.Println(divideArray([]int{1, 3, 4, 8, 7, 9, 3, 5, 1}, 2))
	fmt.Println(divideArray([]int{2, 4, 2, 2, 5, 2}, 2))
	fmt.Println(divideArray([]int{4, 2, 9, 8, 2, 12, 7, 12, 10, 5, 8, 5, 5, 7, 9, 2, 5, 11}, 14))
	// Your code here
}
