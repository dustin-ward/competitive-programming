package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	ans := 0
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			println("Ans:", ans)
			break
		}

		s := strings.Split(line, ":")
		var id int
		fmt.Sscanf(s[0], "Game %d", &id)

		game := strings.Split(s[1], ";")

		valid := true
		for _, round := range game {
			blocks := strings.Split(round, ",")
			C := make(map[string]int, 0)
			for _, col := range blocks {
				var colour string
				var num int
				fmt.Sscanf(col, "%d %s", &num, &colour)
				C[colour] = max(C[colour], num)
			}
			if C["red"] > 12 || C["green"] > 13 || C["blue"] > 14 {
				valid = false
			}
		}
		if valid {
			ans += id
		}
	}
}
