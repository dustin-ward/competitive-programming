package main

import (
	"bufio"
	"os"
	"strconv"
	"unicode"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	vals := make([]int, 0)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			break
		}

		first := ""
		last := ""
		for _, ch := range line {
			if unicode.IsDigit(rune(ch)) {
				if first == "" {
					first = string(ch)
				}
				last = string(ch)
			}
		}
		first += last
		x, _ := strconv.Atoi(first)
		vals = append(vals, x)
	}
	sum := 0
	for _, v := range vals {
		sum += v
	}
	println("Ans:", sum)
}
