package main

import (
	"bufio"
	"fmt"
	"os"
)

var B []string
var V [][][4]bool

var N, M int
var dy = []int{0, -1, 0, 1}
var dx = []int{-1, 0, 1, 0}

func bounds(i, j int) bool {
	return i >= 0 && i < N && j >= 0 && j < M
}

func f(i, j, dir int) {
	if !bounds(i, j) || V[i][j][dir] {
		return
	}
	V[i][j][dir] = true

	cont := true
	switch B[i][j] {
	case '/':
		if dir%2 == 0 {
			dir = (dir + 3) % 4
		} else {
			dir = (dir + 1) % 4
		}
	case '\\':
		if dir%2 == 0 {
			dir = (dir + 1) % 4
		} else {
			dir = (dir + 3) % 4
		}
	case '-':
		if dir%2 != 0 {
			f(i, j-1, 0)
			f(i, j+1, 2)
			cont = false
		}
	case '|':
		if dir%2 != 1 {
			f(i-1, j, 1)
			f(i+1, j, 3)
			cont = false
		}
	}
	if cont {
		i2 := i + dy[dir]
		j2 := j + dx[dir]
		f(i2, j2, dir)
	}
}

func beam(i, j, dir int) int {
	V = make([][][4]bool, len(B))
	for i, _ := range V {
		V[i] = make([][4]bool, len(B[0]))
	}
	f(i, j, dir)

	ans := 0
	for _, a := range V {
		for _, v := range a {
			if v[0] || v[1] || v[2] || v[3] {
				ans++
			}
		}
	}
	return ans
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	B = make([]string, 0)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]
		B = append(B, line)
	}
	N = len(B)
	M = len(B[0])

	ans := 0

	for i := 0; i < N; i++ {
		ans = max(ans, beam(i, 0, 2))
		ans = max(ans, beam(i, M-1, 0))
	}
	for j := 0; j < N; j++ {
		ans = max(ans, beam(0, j, 3))
		ans = max(ans, beam(N-1, j, 1))
	}
	fmt.Println("Ans:", ans)
}
