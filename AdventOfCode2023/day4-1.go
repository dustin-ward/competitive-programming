package main

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	ans := 0
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]

		s := strings.Split(line, ": ")
		s = strings.Split(s[1], "| ")
		scard := strings.Fields(s[0])
		smycard := strings.Fields(s[1])
		card := make(map[int]bool)
		for _, n := range scard {
			g, _ := strconv.Atoi(n)
			card[g] = true
		}

		pts := 0
		for _, n := range smycard {
			g, _ := strconv.Atoi(n)
			if _, ok := card[g]; ok {
				if pts == 0 {
					pts++
				} else {
					pts <<= 1
				}
			}
		}

		ans += pts
	}
	println("Ans:", ans)
}
