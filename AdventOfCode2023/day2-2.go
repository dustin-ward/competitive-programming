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
		C := make(map[string]int, 0)

		power := 0
		for _, round := range game {
			blocks := strings.Split(round, ",")
			for _, col := range blocks {
				var colour string
				var num int
				fmt.Sscanf(col, "%d %s", &num, &colour)
				C[colour] = max(C[colour], num)
			}
		}
		power = C["red"] * C["blue"] * C["green"]
		ans += power
	}
}
