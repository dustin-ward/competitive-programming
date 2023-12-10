package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type pii struct {
	fst int
	snd int
}

var N, M int
var dy = []int{0, -1, 0, 1}
var dx = []int{-1, 0, 1, 0}

func bounds(i, j int) bool {
	return i >= 0 && i < N && j >= 0 && j < M
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	B := make([]string, 0)
	var S pii
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]
		B = append(B, line)

		i := strings.Index(line, "S")
		if i != -1 {
			S = pii{
				len(B) - 1,
				i,
			}
		}
	}
	N = len(B)
	M = len(B[0])

	dt := []string{
		"-LF",
		"|7F",
		"-J7",
		"|LJ",
	}
	var dir int
	for k := 0; k < 4; k++ {
		i2 := S.fst + dy[k]
		j2 := S.snd + dx[k]

		if bounds(i2, j2) && strings.Index(dt[k], string(B[i2][j2])) != -1 {
			dir = k
		}
	}

	ans := 1
	dt = []string{
		"-L F",
		"7|F ",
		" J-7",
		"J L|",
	}
	i := S.fst + dy[dir]
	j := S.snd + dx[dir]
	for B[i][j] != 'S' {
		ans++
		dir = strings.Index(dt[dir], string(B[i][j]))
		i += dy[dir]
		j += dx[dir]
	}

	fmt.Println("Ans:", ans/2)
}
