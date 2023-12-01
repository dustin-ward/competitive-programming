package main

import (
	"bufio"
	"os"
	"strings"
	"unicode"
)

func strToNum(s string) int {
	if strings.HasPrefix(s, "one") {
		return 1
	} else if strings.HasPrefix(s, "two") {
		return 2
	} else if strings.HasPrefix(s, "three") {
		return 3
	} else if strings.HasPrefix(s, "four") {
		return 4
	} else if strings.HasPrefix(s, "five") {
		return 5
	} else if strings.HasPrefix(s, "six") {
		return 6
	} else if strings.HasPrefix(s, "seven") {
		return 7
	} else if strings.HasPrefix(s, "eight") {
		return 8
	} else if strings.HasPrefix(s, "nine") {
		return 9
	}

	return 0
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	vals := make([]int, 0)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			break
		}

		first := -1
		last := -1
		for i, ch := range line {
			if unicode.IsDigit(rune(ch)) || strToNum(line[i:]) != 0 {
				n := isNum(line[i:])
				if n == 0 {
					n = int(ch - rune('0'))
				}
				if first == -1 {
					first = n
				}
				last = n
			}
		}
		first *= 10
		first += last
		vals = append(vals, first)
	}

	sum := 0
	for _, v := range vals {
		sum += v
	}
	println("Ans:", sum)
}
