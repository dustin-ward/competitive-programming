package main

import (
	"bufio"
	"fmt"
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

		s := strings.Split(line, " ")
		R := make([][]int, 1)
		for _, v := range s {
			x, _ := strconv.Atoi(v)
			R[0] = append(R[0], x)
		}

		zero := false
		for !zero {
			n := len(R)
			next := make([]int, 0)
			zero = true
			for i := 0; i < len(R[n-1])-1; i++ {
				x := R[n-1][i+1] - R[n-1][i]
				if x != 0 {
					zero = false
				}
				next = append(next, x)
			}
			R = append(R, next)
		}

		for i := len(R) - 1; i > 0; i-- {
			R[i-1] = append(R[i-1], R[i-1][len(R[i-1])-1]+R[i][len(R[i])-1])
		}

		ans += R[0][len(R[0])-1]
	}
	fmt.Println("Ans:", ans)
}
