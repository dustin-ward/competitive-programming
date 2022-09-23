package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
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

type edge struct {
	u int
	v int
	w int
}

func main() {
	defer writer.Flush()

	var n, m int
	scanf("%d %d\n", &n, &m)
	for n != 0 {
		edges := make([]*edge, m)
		for i := 0; i < m; i++ {
			var u, v, w int
			scanf("%d %d %d\n", &u, &v, &w)
			if u > v {
				u, v = v, u
			}
			e := edge{u, v, w}
			edges[i] = &e
		}

		sort.Slice(edges, func(i, j int) bool { return edges[i].w < edges[j].w })

		ans := 0
		uf := NewUnionFind(n)
		var mst []*edge
		for _, e := range edges {
			if uf.find(e.u) != uf.find(e.v) {
				mst = append(mst, e)
				ans += e.w
				uf.merge(e.u, e.v)
			}
		}

		possible := true
		for i := 0; i < n; i++ {
			if uf.find(i) != uf.find(0) {
				possible = false
				break
			}
		}
		if !possible {
			printf("Impossible\n")
			scanf("%d %d\n", &n, &m)
			continue
		}

		sort.Slice(mst, func(i, j int) bool {
			if mst[i].u < mst[j].u {
				return true
			} else if mst[i].u == mst[j].u {
				return mst[i].v < mst[j].v
			} else {
				return false
			}
		})

		printf("%d\n", ans)
		for _, e := range mst {
			printf("%d %d\n", e.u, e.v)
		}

		scanf("%d %d\n", &n, &m)
	}
}
