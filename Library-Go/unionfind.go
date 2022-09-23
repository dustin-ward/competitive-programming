package unionfind

type unionFind struct {
	howMany int
	uf      []elem
}

type elem struct {
	p    int
	rank int
}

func NewUnionFind(n int) *unionFind {
	uf := new(unionFind)
	uf.howMany = n
	uf.uf = make([]elem, n)
	for i := 0; i < n; i++ {
		uf.uf[i].p = i
	}
	return uf
}

func (uf *unionFind) Find(x int) int {
	if uf.uf[x].p == x {
		return x
	} else {
		return uf.Find(uf.uf[x].p)
	}
}

func (uf *unionFind) Merge(x, y int) bool {
	res1 := uf.Find(x)
	res2 := uf.Find(y)
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
