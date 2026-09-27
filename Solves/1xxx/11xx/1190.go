func reverseParentheses(s string) string {
	stack := []string{}
	current := ""

	for _, ch := range s {

		if ch == '(' {
			stack = append(stack, current)
			current = ""

		} else if ch == ')' {
			runes := []rune(current)

			for i, j := 0, len(runes)-1; i < j; i, j = i+1, j-1 {
				runes[i], runes[j] = runes[j], runes[i]
			}

			current = string(runes)

			previous := stack[len(stack)-1]
			stack = stack[:len(stack)-1]

			current = previous + current

		} else {
			current += string(ch)
		}
	}

	return current
}