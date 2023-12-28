// Gross
package main

import (
	"bufio"
	"fmt"
	"math/rand"
	"os"
	"sort"
	"strings"

	lib "github.com/dustin-ward/comp-lib-go"
)

const SAMPLES = 100

var M map[string]int
var Mrev map[int]string

func getIdx(s string) int {
	if _, ok := M[s]; !ok {
		Mrev[len(M)] = s
		M[s] = len(M)
	}
	return M[s]
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	cons := make(map[string]map[string]bool)
	M = make(map[string]int)
	Mrev = make(map[int]string)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]

		s := strings.Split(line, ": ")
		u := s[0]
		if cons[u] == nil {
			cons[u] = make(map[string]bool)
		}
		for _, v := range strings.Split(s[1], " ") {
			if cons[v] == nil {
				cons[v] = make(map[string]bool)
			}
			cons[u][v] = true
			cons[v][u] = true
		}
	}
	N := len(cons)
	G := lib.NewGraphLst(N)

	for u, set := range cons {
		for v, _ := range set {
			G.AddEdge(getIdx(u), getIdx(v), 1)
		}
	}

	most_visited := make([][]int, N)
	for i, _ := range most_visited {
		most_visited[i] = make([]int, N)
	}

	for X := 0; X < SAMPLES; X++ {
		u := rand.Intn(N)
		for x := 0; x < 10; x++ {
			v := rand.Intn(N)

			_, P := lib.Dijkstra_Sparse(G, u)
			path := lib.GetPath(v, P)

			for i := 0; i < len(path)-1; i++ {
				l := min(path[i], path[i+1])
				r := max(path[i], path[i+1])
				most_visited[l][r]++
			}
		}
	}

	type piii struct {
		u, v int
		c    int
	}
	E := make([]piii, 0, N*N)
	for i := 0; i < N; i++ {
		for j := 0; j < N; j++ {
			E = append(E, piii{i, j, most_visited[i][j]})
		}
	}
	sort.Slice(E, func(i, j int) bool {
		return E[i].c > E[j].c
	})
	E = E[:3]
	Emap := make(map[int]int)
	for _, v := range E {
		Emap[v.u] = v.v
		Emap[v.v] = v.u
	}
	if len(Emap) != 6 {
		panic("Bad attempt")
	}

	V := make([]bool, N)
	Q := make([]int, 1)
	Q[0] = N - 1
	V[N-1] = true
	ans := 0
	for len(Q) > 0 {
		cur := Q[0]
		Q = Q[1:]

		ans++

		for _, e := range G.Adj[cur] {
			if !V[e.To] {
				if s, ok := Emap[cur]; ok && s == e.To {
					continue
				}

				V[e.To] = true
				Q = append(Q, e.To)
			}
		}
	}
	fmt.Println("Ans:", (N-ans)*ans)
}
