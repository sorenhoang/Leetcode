package l76

import (
	"math"
)

func minWindow(s string, t string) string {
	if len(s) < len(t) {
		return ""
	}

	freqMap := [128]int{}
	count := len(t)
	start, minStart, minLen := 0, 0, math.MaxInt32

	// Initialize the frequency map with characters from t
	for _, c := range t {
		freqMap[c]++
	}

	// Start the sliding window
	for end := 0; end < len(s); end++ {
		if freqMap[s[end]] > 0 {
			count--
		}
		freqMap[s[end]]--

		// Try to minimize the window
		for count == 0 {
			if end-start+1 < minLen {
				minStart = start
				minLen = end - start + 1
			}

			freqMap[s[start]]++
			if freqMap[s[start]] > 0 {
				count++
			}
			start++
		}
	}

	if minLen == math.MaxInt32 {
		return ""
	}
	return s[minStart : minStart+minLen]
}

func main() {
	// Example usage
	s := "ADOBECODEBANC"
	t := "ABC"
	result := minWindow(s, t)
	println("Minimum window substring:", result) // Output: "BANC"
}
