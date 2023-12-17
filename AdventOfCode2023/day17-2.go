package main

import (
	"bufio"
	"fmt"
	"os"

	lib "github.com/dustin-ward/comp-lib-go"
)

var N int
var R, C int
var dy = []int{0, -1, 0, 1}
var dx = []int{-1, 0, 1, 0}

func bounds(i, j int) bool {
	return i >= 0 && i < R && j >= 0 && j < C
}

func getIdx(i, j, dir, s int) int {
	return (i * R * 4 * 11) + (j * 4 * 11) + (dir * 11) + s
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
	R = len(B)
	C = len(B[0])

	N = (R * C * 4 * 11) + 2
	G := lib.NewGraphAdj(N)

	for i := 0; i < R; i++ {
		for j := 0; j < C; j++ {
			for k := 0; k < 4; k++ {
				for s := 0; s < 11; s++ {
					//Straight
					i2 := i + dy[k]
					j2 := j + dx[k]
					if bounds(i2, j2) && s != 10 {
						G.AddEdge(getIdx(i, j, k, s), getIdx(i2, j2, k, s+1), int(rune(B[i2][j2])-'0'))
					}

					if s >= 4 {
						//Left
						k2 := (k + 1) % 4
						i2 = i + dy[k2]
						j2 = j + dx[k2]
						if bounds(i2, j2) {
							G.AddEdge(getIdx(i, j, k, s), getIdx(i2, j2, k2, 1), int(rune(B[i2][j2])-'0'))
						}

						//Right
						k2 = (k + 3) % 4
						i2 = i + dy[k2]
						j2 = j + dx[k2]
						if bounds(i2, j2) {
							G.AddEdge(getIdx(i, j, k, s), getIdx(i2, j2, k2, 1), int(rune(B[i2][j2])-'0'))
						}
					}
				}
			}
		}
	}
	for k := 0; k < 4; k++ {
		G.AddEdge(N-2, getIdx(0, 0, k, 0), 0)
	}
	for k := 0; k < 4; k++ {
		for s := 4; s < 11; s++ {
			G.AddEdge(getIdx(R-1, C-1, k, s), N-1, 0)
		}
	}

	D := lib.Dijkstra_Sparse(G, N-2)
	fmt.Println("Ans:", D[N-1])
}
