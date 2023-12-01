package main

import (
	"bufio"
	"os"
	"sort"
	"strconv"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	sum := 0
	E := make([]int, 0)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			E = append(E, -sum)
			break
		}

		if line == "\n" {
			E = append(E, -sum)
			sum = 0
		} else {
			x, _ := strconv.Atoi(line[:len(line)-1])
			sum += x
		}
	}

	sort.Ints(E)
	ans := E[0] + E[1] + E[2]
	println("Ans:", -ans)
}
