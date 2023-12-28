package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
	"strings"
)

const EPSILON = 1e-8

const MIN = 200000000000000.
const MAX = 400000000000000.

// const MIN = 7.
// const MAX = 27.

type Point struct {
	x, y float64
}

func intersect_iline(a, b, c, d Point, p *Point) int {
	var r float64
	var denom, num1 float64

	// assert((a.x != b.x || a.y != b.y) && (c.x != d.x || c.y != d.y));

	num1 = (a.y-c.y)*(d.x-c.x) - (a.x-c.x)*(d.y-c.y)
	// num2 = (a.y-c.y)*(b.x-a.x) - (a.x-c.x)*(b.y-a.y)
	denom = (b.x-a.x)*(d.y-c.y) - (b.y-a.y)*(d.x-c.x)

	if math.Abs(denom) >= EPSILON {
		r = num1 / denom
		p.x = a.x + r*(b.x-a.x)
		p.y = a.y + r*(b.y-a.y)
		return 1
	} else {
		if math.Abs(num1) >= EPSILON {
			return 0
		} else {
			return -1
		}
	}
}

const (
	X = 0
	Y = 1
	Z = 2
)

type Hail struct {
	S [3]float64
	V [3]float64
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
			H.S[i], _ = strconv.ParseFloat(str, 64)
			i++
		}
		s1 = strings.Split(s[1], ", ")
		i = 0
		for _, str := range s1 {
			if str == "" {
				continue
			}
			str = strings.TrimSpace(str)
			H.V[i], _ = strconv.ParseFloat(str, 64)
			i++
		}

		Hs = append(Hs, H)
	}

	ans := 0
	for i, _ := range Hs {
		for j := i + 1; j < len(Hs); j++ {
			var P Point
			a := Point{Hs[i].S[X], Hs[i].S[Y]}
			b := Point{Hs[i].S[X] + Hs[i].V[X], Hs[i].S[Y] + Hs[i].V[Y]}
			c := Point{Hs[j].S[X], Hs[j].S[Y]}
			d := Point{Hs[j].S[X] + Hs[j].V[X], Hs[j].S[Y] + Hs[j].V[Y]}

			ret := intersect_iline(a, b, c, d, &P)
			if ret != 0 && (P.x >= MIN && P.y >= MIN && P.x <= MAX && P.y <= MAX) {
				if (Hs[i].V[X] > 0 && P.x < Hs[i].S[X]) ||
					(Hs[i].V[X] < 0 && P.x > Hs[i].S[X]) ||
					(Hs[i].V[Y] > 0 && P.y < Hs[i].S[Y]) ||
					(Hs[i].V[Y] < 0 && P.y > Hs[i].S[Y]) ||
					(Hs[j].V[X] > 0 && P.x < Hs[j].S[X]) ||
					(Hs[j].V[X] < 0 && P.x > Hs[j].S[X]) ||
					(Hs[j].V[Y] > 0 && P.y < Hs[j].S[Y]) ||
					(Hs[j].V[Y] < 0 && P.y > Hs[j].S[Y]) {
					continue
				}
				fmt.Println(Hs[i], Hs[j])
				fmt.Println(i, j, "P:", P)
				ans++
			}
		}
	}
	fmt.Println("Ans:", ans)
}
