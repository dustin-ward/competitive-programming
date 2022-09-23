package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

type UnionFind struct {
	howMany int
	uf      []elem
}

type elem struct {
	p    int
	rank int
}

func NewUnionFind(n int) *UnionFind {
	uf := new(UnionFind)
	uf.howMany = n
	uf.uf = make([]elem, n)
	for i := 0; i < n; i++ {
		uf.uf[i].p = i
	}
	return uf
}

func (uf *UnionFind) find(x int) int {
	if uf.uf[x].p == x {
		return x
	} else {
		return uf.find(uf.uf[x].p)
	}
}

func (uf *UnionFind) merge(x, y int) bool {
	res1 := uf.find(x)
	res2 := uf.find(y)
	if res1 != res2 {
		if uf.uf[res1].rank > uf.uf[res2].rank {
			uf.uf[res2].p = res1
		} else {
			uf.uf[res1].p = res2
			if uf.uf[res1].rank == uf.uf[res2].rank {
				uf.uf[res2].rank++
			}
		}
		return true
	}
	return false
}

func min(a, b int64) int64 {
	if a <= b {
		return a
	}
	return b
}

func binomialCoefficient(n, k int64) int64 {
	if k == 0 || k == n {
		return 1
	}
	k = min(k, n-k)
	var ans int64
	var i int64
	ans = 1
	for i = 1; i <= k; i++ {
		ans *= (n - k + i)
		ans /= i
	}
	return ans
}

func main() {
	defer writer.Flush()

	var N, M int
	scanf("%d %d\n", &N, &M)

	uf := NewUnionFind(N)
	for i := 0; i < M; i++ {
		var u, v int
		scanf("%d %d\n", &u, &v)
		uf.merge(u-1, v-1)
	}

	total := binomialCoefficient(int64(N), 2)
	var connected int64 = 0

	connectedComponents := make(map[int]int, N)
	for i := 0; i < N; i++ {
		connectedComponents[uf.find(i)]++
	}

	for _, i := range connectedComponents {
		if i > 1 {
			connected += binomialCoefficient(int64(i), 2)
		}
	}

	printf("%.7f\n", float64(connected)/float64(total))
}
