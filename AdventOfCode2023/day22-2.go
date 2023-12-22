package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strconv"
	"strings"
)

type coord struct {
	x, y, z int
}

type Brick [2]coord

var grid [10][10][500]int

func main() {
	reader := bufio.NewReader(os.Stdin)
	for i := 0; i < 10; i++ {
		for j := 0; j < 10; j++ {
			for k := 0; k < 500; k++ {
				grid[i][j][k] = -1
			}
		}
	}

	bricks := make([]Brick, 0)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]

		s := strings.Split(line, "~")
		var b Brick
		for i, p := range s {
			c := strings.Split(p, ",")
			b[i].x, _ = strconv.Atoi(c[0])
			b[i].y, _ = strconv.Atoi(c[1])
			b[i].z, _ = strconv.Atoi(c[2])
		}

		bricks = append(bricks, b)
	}

	sort.Slice(bricks, func(i, j int) bool {
		return min(bricks[i][0].z, bricks[i][1].z) <= min(bricks[j][0].z, bricks[j][1].z)
	})

	on := make([]map[int]bool, len(bricks))
	under := make([]map[int]bool, len(bricks))
	for i, _ := range on {
		on[i] = make(map[int]bool, 0)
		under[i] = make(map[int]bool, 0)
	}
	for i, b := range bricks {
		for {
			landed := false
			for x := min(b[0].x, b[1].x); x <= max(b[0].x, b[1].x); x++ {
				for y := min(b[0].y, b[1].y); y <= max(b[0].y, b[1].y); y++ {
					z := min(b[0].z, b[1].z) - 1
					if z == 0 || grid[x][y][z] != -1 {
						landed = true
						if z != 0 {
							on[i][grid[x][y][z]] = true
							under[grid[x][y][z]][i] = true
						}
					}
				}
			}
			if landed {
				for x := min(b[0].x, b[1].x); x <= max(b[0].x, b[1].x); x++ {
					for y := min(b[0].y, b[1].y); y <= max(b[0].y, b[1].y); y++ {
						for z := min(b[0].z, b[1].z); z <= max(b[0].z, b[1].z); z++ {
							grid[x][y][z] = i
						}
					}
				}
				break
			} else {
				b[0].z--
				b[1].z--
			}
		}
	}

	ans := 0
	for i, _ := range bricks {
		sum := 0
		Q := make([]int, 1)
		Q[0] = i
		D := make(map[int]bool)
		for len(Q) > 0 {
			cur := Q[0]
			Q = Q[1:]
			D[cur] = true

			for j, _ := range under[cur] {
				if _, ok := D[j]; ok {
					continue
				}
				numUnder := 0
				for k, _ := range on[j] {
					if _, ok := D[k]; !ok {
						numUnder++
					}
				}
				if numUnder == 0 {
					D[j] = true
					sum++
					Q = append(Q, j)
				}
			}
		}
		ans += sum
	}
	fmt.Println("Ans:", ans)
}
