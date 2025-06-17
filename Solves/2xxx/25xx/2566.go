package main

import (
	"fmt"
	"strconv"
	"strings"
)

func minMaxDifference(num int) int {
	s := strconv.Itoa(num)
	tmp := s

	for _, c := range s {
		if c == '9' {
			continue
		}
		tmp = strings.Replace(s, string(c), "9", -1)
		break
	}
	ans, _ := strconv.Atoi(tmp)
	tmp = s
	for _, c := range s {
		if c == '0' {
			continue
		}
		tmp = strings.Replace(s, string(c), "0", -1)
		break
	}
	minus, _ := strconv.Atoi(tmp)
	return ans - minus
}

func main() {
	// Your code here
	fmt.Println(minMaxDifference(1234)) // Example usage
	fmt.Println(minMaxDifference(1009)) // Example usage
}
