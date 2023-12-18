package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"

	lib "github.com/dustin-ward/comp-lib-go"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	cur := lib.Point{}
	B := 0
	polygon := []lib.Point{cur}
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]

		s := strings.Split(line, " ")

		x64, _ := strconv.ParseInt(s[2][2:7], 16, 64)
		x := int(x64)
		dir := s[2][7:8]

		B += x
		var nextPoint lib.Point
		if dir == "0" {
			nextPoint = lib.Point{cur.X + float64(x), cur.Y}
		}
		if dir == "1" {
			nextPoint = lib.Point{cur.X, cur.Y + float64(x)}
		}
		if dir == "2" {
			nextPoint = lib.Point{cur.X - float64(x), cur.Y}
		}
		if dir == "3" {
			nextPoint = lib.Point{cur.X, cur.Y - float64(x)}
		}

		cur = nextPoint
		polygon = append(polygon, cur)
	}

	A := int(lib.AreaPolygon(polygon))
	I := A + 1 + B/2

	fmt.Println("Ans:", I)
}
