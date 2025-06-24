package main

import (
	"strconv"
)

func countDigits(num int) int {
	return len(strconv.Itoa(num))
}

func longestCommonPrefix(arr1 []int, arr2 []int) int {
	var ans int
	pref := make(map[int]int)
	for _, num := range arr1 {
		for num > 0 {
			pref[num]++
			num /= 10
		}
	}

	for _, num := range arr2 {
		for num > 0 {

			if pref[num] > 0 {
				ans = max(ans, countDigits(num))
				break
			}
			num /= 10
		}
	}
	return ans
}
func main() {
	arr1 := []int{1, 10, 100}
	arr2 := []int{1000}
	println(longestCommonPrefix(arr1, arr2)) // Output: 1

	arr1 = []int{1, 2, 3}
	arr2 = []int{4, 4, 4}
	println(longestCommonPrefix(arr1, arr2)) // Output: 0
}
