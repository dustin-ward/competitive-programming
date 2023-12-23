package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"

	lib "github.com/dustin-ward/comp-lib-go"
)

var B []string
var R, C int
var N int
var dy = []int{0, -1, 0, 1}
var dx = []int{-1, 0, 1, 0}
var G *lib.GraphLst
var dest int
var V []bool
var ans int

func bounds(i, j int) bool {
	return i >= 0 && i < R && j >= 0 && j < C
}

func getIdx(i, j int) int {
	return (i * R) + j
}

func f(n, d int) {
	if n == dest {
		ans = max(ans, d)
		return
	}

	V[n] = true
	for _, e := range G.Adj[n] {
		if !V[e.To] {
			f(e.To, d+1)
		}
	}
	V[n] = false
}

func main() {
	B = make([]string, 0)
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]
		B = append(B, line)
	}
	R = len(B)
	C = len(B[0])
	N = R * C
	V = make([]bool, N)

	G = lib.NewGraphLst(N)

	for i, _ := range B {
		for j, _ := range B[i] {
			switch B[i][j] {
			case '.', '<', '>', 'v', '^':
				for k := 0; k < 4; k++ {
					i2 := i + dy[k]
					j2 := j + dx[k]
					if bounds(i2, j2) && B[i2][j2] != '#' {
						G.AddEdge(getIdx(i, j), getIdx(i2, j2), 1)
					}
				}
			}
		}
	}
	srcJ := strings.Index(B[0], ".")
	src := getIdx(0, srcJ)
	destJ := strings.Index(B[R-1], ".")
	dest = getIdx(R-1, destJ)

	f(src, 0)

	fmt.Println("Ans:", ans)
}
