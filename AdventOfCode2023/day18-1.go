package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type pii struct {
	fst int
	snd int
}

var N, M int
var dy = []int{0, -1, 0, 1}
var dx = []int{-1, 0, 1, 0}
var FF [][]bool
var B [][]rune

func bounds(i, j int) bool {
	return i >= 0 && i < N && j >= 0 && j < M
}

func fill(i, j int) {
	if !bounds(i, j) || B[i][j] == '#' {
		return
	}
	Q := []pii{pii{
		i,
		j,
	}}
	FF[i][j] = true

	for len(Q) > 0 {
		cur := Q[0]
		Q = Q[1:]
		for k := 0; k < 4; k++ {
			i2 := cur.fst + dy[k]
			j2 := cur.snd + dx[k]
			if bounds(i2, j2) && !FF[i2][j2] && B[i2][j2] != '#' {
				FF[i2][j2] = true
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

	ptsmap := make(map[int]bool, 0)
	pts := make([]pii, 0)
	cur := pii{}
	minX := 0
	minY := 0
	maxX := 0
	maxY := 0
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]

		s := strings.Split(line, " ")

		dir := s[0]
		x, _ := strconv.Atoi(s[1])

		if dir == "D" {
			for i := 0; i < x; i++ {
				pts = append(pts, pii{cur.fst + i, cur.snd})
				ptsmap[(cur.fst+i)*10000+cur.snd] = true
			}
			cur.fst += x
		}
		if dir == "U" {
			for i := 0; i < x; i++ {
				pts = append(pts, pii{cur.fst - i, cur.snd})
				ptsmap[(cur.fst-i)*10000+cur.snd] = true
			}
			cur.fst -= x
		}
		if dir == "R" {
			for i := 0; i < x; i++ {
				pts = append(pts, pii{cur.fst, cur.snd + i})
				ptsmap[(cur.fst*10000)+(cur.snd+i)] = true
			}
			cur.snd += x
		}
		if dir == "L" {
			for i := 0; i < x; i++ {
				pts = append(pts, pii{cur.fst, cur.snd - i})
				ptsmap[(cur.fst*10000)+(cur.snd-i)] = true
			}
			cur.snd -= x
		}
		maxY = max(maxY, cur.fst)
		maxX = max(maxX, cur.snd)
		minY = min(minY, cur.fst)
		minX = min(minX, cur.snd)
	}

	N = maxY - minY + 1
	M = maxX - minX + 1

	FF = make([][]bool, N)
	B = make([][]rune, N)
	for i, _ := range B {
		FF[i] = make([]bool, M)
		B[i] = []rune(strings.Repeat(".", M))
	}

	for _, p := range pts {
		i := p.fst - minY
		j := p.snd - minX
		B[i][j] = '#'
	}

	ans := len(ptsmap)
	idx := strings.Index(string(B[1]), "#.")
	fill(1, idx+1)
	for _, r := range FF {
		for _, v := range r {
			if v {
				ans++
			}
		}
	}
	fmt.Println("Ans:", ans)
}
