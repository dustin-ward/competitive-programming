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

func main() {
	var n, q int
	scanf("%d %d\n", &n, &q)
	uf := NewUnionFind(n)
	ans := ""
	for i := 0; i < q; i++ {
		var a, b int
        var c string
		scanf("%s %d %d\n", &c, &a, &b)

		if c == "=" {
			uf.merge(a, b)
		} else {
			if uf.find(a) == uf.find(b) {
				ans += "yes\n"
			} else {
				ans += "no\n"
			}
		}
	}
	printf("%s", ans)
	defer writer.Flush()
}
