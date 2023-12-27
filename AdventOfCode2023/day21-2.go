package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

var N, M int
var B []string
var V []bool
var dy = []int{0, -1, 0, 1}
var dx = []int{-1, 0, 1, 0}

type pii struct {
	fst, snd int
	thd, fth int
}

func getIdx(i, j int) int {
	return (i * N) + j
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
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
		N++
		M = len(line)

		if idx := strings.Index(line, "S"); idx != -1 {
			si, sj = N-1, idx
		}

		newV := make([]bool, len(line))
		for i, ch := range line {
			newV[i] = ch == '.' || ch == 'S'
		}
		V = append(V, newV...)
	}
	fmt.Println(N, M)

	steps := make([]int, 0)
	Q := make(map[pii]bool)
	Q[pii{si, sj, si, sj}] = true
	for s := 0; s < 3*N; s++ {
		if s%N == N/2 {
			steps = append(steps, len(Q))
		}

		newQ := make(map[pii]bool)
		for p, _ := range Q {
			i := p.fst
			j := p.snd
			ai := p.thd
			aj := p.fth
			for k := 0; k < 4; k++ {
				i2 := i + dy[k]
				j2 := j + dx[k]
				ai2 := ((ai + dy[k]) + N) % N
				aj2 := ((aj + dx[k]) + M) % M
				idx := getIdx(ai2, aj2)
				if V[idx] {
					newQ[pii{i2, j2, ai2, aj2}] = true
				}
			}
		}
		Q = newQ
	}
	fmt.Println("Steps:", steps)

	ans := f(NUM_STEPS/N, steps[0], steps[1], steps[2])
	fmt.Println("Ans:", ans)
}

const NUM_STEPS = 26501365

func f(n, a, b, c int) int {
	return a + n*(b-a+(n-1)*(c-b-b+a)/2)
}
