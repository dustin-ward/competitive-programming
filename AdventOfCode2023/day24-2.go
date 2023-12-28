package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const (
	X = 0
	Y = 1
	Z = 2
)

type Hail struct {
	S [3]int
	V [3]int
}

func abs(x int) int {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	Hs := make([]Hail, 0)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]
		s := strings.Split(line, " @ ")

		var H Hail
		s1 := strings.Split(s[0], ", ")
		i := 0
		for _, str := range s1 {
			if str == "" {
				continue
			}
			str = strings.TrimSpace(str)
			// H.S[i], _ = strconv.ParseFloat(str, 64)
			H.S[i], _ = strconv.Atoi(str)
			i++
		}
		s1 = strings.Split(s[1], ", ")
		i = 0
		for _, str := range s1 {
			if str == "" {
				continue
			}
			str = strings.TrimSpace(str)
			// H.V[i], _ = strconv.ParseFloat(str, 64)
			H.V[i], _ = strconv.Atoi(str)
			i++
		}

		Hs = append(Hs, H)
	}

	var V [3]map[int]bool
	for i, _ := range V {
		V[i] = make(map[int]bool)
	}

	for i := 0; i < len(Hs); i++ {
		for j := i + 1; j < len(Hs); j++ {
			A := Hs[i]
			B := Hs[j]

			for a := X; a <= Z; a++ {
				if A.V[a] == B.V[a] && abs(A.V[a]) > 100 {
					vset := make(map[int]bool)
					for v := -1000; v <= 1000; v++ {
						if v == A.V[a] {
							continue
						}
						if (B.S[a]-A.S[a])%(v-A.V[a]) == 0 {
							vset[v] = true
						}
					}

					if len(V[a]) != 0 {
						newset := make(map[int]bool)
						for v, _ := range vset {
							if _, ok := V[a][v]; ok {
								newset[v] = true
							}
						}
						V[a] = newset
					} else {
						V[a] = vset
					}
				}
			}
		}
	}

	var fv [3]int
	for a := X; a <= Z; a++ {
		for k, _ := range V[a] {
			fv[a] = k
		}
	}
	vx, vy, vz := fv[0], fv[1], fv[2]

	A := Hs[0]
	B := Hs[1]
	ma := float64(A.V[Y]-vy) / float64(A.V[X]-vx)
	mb := float64(B.V[Y]-vy) / float64(B.V[X]-vx)
	ca := float64(A.S[Y]) - (ma * float64(A.S[X]))
	cb := float64(B.S[Y]) - (mb * float64(B.S[X]))
	finalX := int((cb - ca) / (ma - mb))
	finalY := int(ma*float64(finalX) + ca)
	t := (finalX - A.S[X]) / (A.V[X] - vx)
	finalZ := A.S[Z] + (A.V[Z]-vz)*t

	fmt.Println("Ans:", finalX+finalY+finalZ)
}
