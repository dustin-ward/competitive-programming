package main

import (
	"fmt"
	"log"
)

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
	fmt.Scanf("%d %d", &n, &q)
	uf := NewUnionFind(n)
	ans := ""
	for i := 0; i < q; i++ {
		var a, b, c int
		if _, err := fmt.Scanf("%c %d %d", &c, &a, &b); err != nil {
			log.Fatal(err.Error())
		}

		if c == '=' {
			uf.merge(a, b)
		} else {
			if uf.find(a) == uf.find(b) {
				ans += "yes\n"
			} else {
				ans += "no\n"
			}
		}
	}
	fmt.Println(ans)
}
