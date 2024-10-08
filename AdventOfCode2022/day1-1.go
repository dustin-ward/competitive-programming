package main

import (
	"bufio"
	"os"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	ans := 0
	sum := 0
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			println("Ans:", ans)
			return
		}

		if line == "\n" {
			ans = max(ans, sum)
			sum = 0
		} else {
            x, _ := strconv.Atoi(line[:len(line)-1])
			sum += x
		}
	}
}
