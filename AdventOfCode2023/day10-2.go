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
var FF [][][]bool
var B []string
var path [][]bool

func bounds(i, j int) bool {
	return i >= 0 && i < N && j >= 0 && j < M
}

func fill(i, j, d int) {
	if !bounds(i, j) || path[i][j] {
		return
	}
	Q := []pii{pii{
		i,
		j,
	}}
	FF[d][i][j] = true

	for len(Q) > 0 {
		cur := Q[0]
		Q = Q[1:]
		for k := 0; k < 4; k++ {
			i2 := cur.fst + dy[k]
			j2 := cur.snd + dx[k]
			if bounds(i2, j2) && !FF[d][i2][j2] && !path[i2][j2] {
				FF[d][i2][j2] = true
				Q = append(Q, pii{
					i2,
					j2,
				})
			}
		}
	}
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	B = make([]string, 0)
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

	// Init
	N = len(B)
	M = len(B[0])
	FF = make([][][]bool, 2)
	for j := 0; j < 2; j++ {
		FF[j] = make([][]bool, N)
		for i := 0; i < N; i++ {
			FF[j][i] = make([]bool, M)
		}
	}
	path = make([][]bool, N)
	for x := 0; x < N; x++ {
		path[x] = make([]bool, M)
	}
	path[S.fst][S.snd] = true

	// Find starting direction
	dt := []string{
		"-LF",
		"|7F",
		"-J7",
		"|LJ",
	}
	startdir := -1
	for k := 0; k < 4; k++ {
		i2 := S.fst + dy[k]
		j2 := S.snd + dx[k]

		if bounds(i2, j2) && strings.Index(dt[k], string(B[i2][j2])) != -1 {
			startdir = k
		}
	}

	// Trace path
	dir := startdir
	i := S.fst + dy[dir]
	j := S.snd + dx[dir]
	dt = []string{
		"-L F",
		"7|F ",
		" J-7",
		"J L|",
	}
	for B[i][j] != 'S' {
		path[i][j] = true
		dir = strings.Index(dt[dir], string(B[i][j]))
		i += dy[dir]
		j += dx[dir]
	}

	// Fill left and right along the path
	dir = startdir
	i = S.fst + dy[dir]
	j = S.snd + dx[dir]
	ds := []string{
		"LF",
		"F7",
		"7J",
		"JL",
	}
	for B[i][j] != 'S' {
		rDir := (dir + 1) % 4
		lDir := (dir + 3) % 4
		fill(i+dy[lDir], j+dx[lDir], 0)
		fill(i+dy[rDir], j+dx[rDir], 1)

		idx := strings.Index(ds[dir], string(B[i][j]))
		if idx != -1 {
			fill(i+dy[dir], j+dx[dir], idx)
		}
		dir = strings.Index(dt[dir], string(B[i][j]))

		i += dy[dir]
		j += dx[dir]
	}

	// Sum up left vs right
	ans := make([]int, 2)
	for i := 0; i < 2; i++ {
		for j := 0; j < N; j++ {
			for k := 0; k < M; k++ {
				if FF[i][j][k] {
					ans[i]++
				}
			}
		}
	}

	// Ans is min of left fill vs right fill
	fmt.Println("Ans:", min(ans[0], ans[1]))
}
