package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func trans(b []string) []string {
	N := len(b)
	M := len(b[0])

	b2 := make([]string, 0)
	for j := 0; j < M; j++ {
		str := make([]rune, N)
		for i := 0; i < N; i++ {
			str[i] = rune(b[i][j])
		}
		b2 = append(b2, string(str))
	}
	return b2
}

func rotCW(b []string) []string {
	N := len(b)
	M := len(b[0])

	b2 := make([]string, M)
	for i := 0; i < M; i++ {
		str := make([]rune, N)
		for j := 0; j < N; j++ {
			str[j] = rune(b[(N-1)-j][i])
		}
		b2[i] = string(str)
	}
	return b2
}

func shift(B []string, dir int) []string {
	rot := false
	if dir%2 > 0 {
		B = rotCW(B)
		dir = (dir + 1) % 4
		rot = true
	}

	b2 := make([]string, len(B))
	M := len(B[0])
	for i, line := range B {
		secs := strings.Split(line, "#")
		newline := ""
		for _, s := range secs {
			x := strings.Count(s, "O")
			if dir == 0 {
				newline += strings.Repeat("O", x) + strings.Repeat(".", len(s)-x) + "#"
			} else if dir == 2 {
				newline += strings.Repeat(".", len(s)-x) + strings.Repeat("O", x) + "#"
			}
		}
		b2[i] = newline[:M]
	}

	if rot {
		for i := 0; i < 3; i++ {
			b2 = rotCW(b2)
		}
	}
	return b2
}

func northLoad(B []string) (load int) {
	M := len(B[0])
	for _, line := range B {
		for i, c := range line {
			if c == 'O' {
				load += M - i
			}
		}
	}
	return
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	B := make([]string, 0)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]
		B = append(B, line)
	}
	B = trans(B)

	// Started at 1000
	const hack = 200
	L := make([]int, hack)
	cycle := 0
	for ; cycle < hack; cycle++ {
		for i := 0; i < 4; i++ {
			B = shift(B, i)
		}
		L[cycle] = northLoad(B)
	}

	pattern := []int{L[len(L)-2], L[len(L)-1]}
	var match, cyclen int
	for i := len(L) - 4; i >= 0; i-- {
		if L[i] == pattern[0] && L[i+1] == pattern[1] {
			match = i
			cyclen = (len(L) - 2) - match
			break
		}
	}

	const oneB = 1000000000
	for cycle < oneB {
		if cycle < oneB-cyclen {
			cycle += cyclen
			continue
		}
		for i := 0; i < 4; i++ {
			B = shift(B, i)
		}
		cycle++
	}
	load := northLoad(B)

	fmt.Println("Ans:", load)
}
