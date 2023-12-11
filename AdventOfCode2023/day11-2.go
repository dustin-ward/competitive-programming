package main

import (
	"bufio"
	"fmt"
	"os"
)

func abs(i int) int {
	if i < 0 {
		return -i
	}
	return i
}

var N, M int

type pii struct {
	fst int
	snd int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	B := make([]string, 0)
	ER := make(map[int]bool, 0)
	EC := make(map[int]bool, 0)
	P := make([]pii, 0)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]

		added := false
		for i := 0; i < len(line); i++ {
			if line[i] == '#' {
				P = append(P, pii{
					len(B),
					i,
				})
				added = true
			}
		}

		if !added {
			ER[len(B)] = true
		}
		B = append(B, line)
	}
	N = len(B)
	M = len(B[0])

	for j := 0; j < M; j++ {
		empty := true
		for i := 0; i < N; i++ {
			if B[i][j] == '#' {
				empty = false
				break
			}
		}
		if empty {
			EC[j] = true
		}
	}

	ans := 0
	for i := 0; i < len(P); i++ {
		for j := i + 1; j < len(P); j++ {
			p1 := P[i]
			p2 := P[j]
			dx := abs(p1.fst - p2.fst)
			dy := abs(p1.snd - p2.snd)
			dis := dx + dy

			for k := min(p1.fst, p2.fst); k < max(p1.fst, p2.fst); k++ {
				if _, ok := ER[k]; ok {
					dis += 999999
				}
			}
			for k := min(p1.snd, p2.snd); k < max(p1.snd, p2.snd); k++ {
				if _, ok := EC[k]; ok {
					dis += 999999
				}
			}

			ans += dis
		}
	}

	fmt.Println("Ans:", ans)
}
