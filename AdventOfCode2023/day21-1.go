package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

const STEPS = 64
const MAX = (1 << 62)

var N, M int
var B []string
var V [][]int
var dy = []int{0, -1, 0, 1}
var dx = []int{-1, 0, 1, 0}

func bounds(i, j int) bool {
	return i >= 0 && i < N && j >= 0 && j < M
}

func f(i, j, d int) {
	if V[i][j] <= d {
		return
	}
	if d == STEPS {
		V[i][j] = d
		return
	}
	if d%2 == 0 {
		V[i][j] = d
	}

	for k := 0; k < 4; k++ {
		i2 := i + dy[k]
		j2 := j + dx[k]
		if bounds(i2, j2) && B[i2][j2] != '#' {
			f(i2, j2, d+1)
		}
	}
}

func main() {
	B = make([]string, 0)
	reader := bufio.NewReader(os.Stdin)
	var si, sj int
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]
		B = append(B, line)

		if idx := strings.Index(line, "S"); idx != -1 {
			si, sj = len(B)-1, idx
		}
	}
	N = len(B)
	M = len(B[0])
	V = make([][]int, N)
	for i, _ := range V {
		V[i] = make([]int, M)
		for j, _ := range V[i] {
			V[i][j] = MAX
		}
	}

	f(si, sj, 0)

	ans := 0
	for _, r := range V {
		for _, v := range r {
			if v != MAX {
				ans++
			}
		}
	}
	fmt.Println("Ans:", ans)
}
