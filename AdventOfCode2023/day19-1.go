package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const CATS = "xmas"

type Part [4]int

type opFunc func(a, b int) bool
type Op struct {
	part int
	val  int
	fn   opFunc
	dest string
}

func lessThan(a, b int) bool {
	return a < b
}

func greaterThan(a, b int) bool {
	return a > b
}

func alwaysTrue(a, b int) bool {
	return true
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	Workflows := make(map[string][]Op)
	Parts := make(map[string][]Part)
	Parts["A"] = make([]Part, 0)
	Parts["R"] = make([]Part, 0)
	for {
		line, _ := reader.ReadString('\n')
		if line == "\n" {
			break
		}
		line = line[:len(line)-1]

		// Workflows
		idx := strings.Index(line, "{")
		name := line[:idx]
		Workflows[name] = make([]Op, 0)
		Parts[name] = make([]Part, 0)

		line = line[idx+1 : len(line)-1]
		ops := strings.Split(line, ",")
		for _, s := range ops {
			idx2 := strings.Index(s, ":")
			if idx2 != -1 {
				dest := s[idx2+1:]
				s = s[:idx2]
				p := s[0]
				op := s[1]
				var fn opFunc
				if op == '<' {
					fn = lessThan
				} else {
					fn = greaterThan
				}
				val, _ := strconv.Atoi(s[2:])
				Workflows[name] = append(Workflows[name], Op{
					strings.Index(CATS, string(p)),
					val,
					fn,
					dest,
				})
			} else {
				Workflows[name] = append(Workflows[name], Op{
					0,
					0,
					alwaysTrue,
					s,
				})
			}
		}
	}

	var totalParts int
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			break
		}
		line = line[:len(line)-1]

		// Parts
		var part Part
		s := strings.Split(line[1:len(line)-1], ",")
		for i, c := range s {
			part[i], _ = strconv.Atoi(c[2:])
		}
		Parts["in"] = append(Parts["in"], part)
		totalParts++
	}

	for len(Parts["A"])+len(Parts["R"]) != totalParts {
		for name, wk := range Workflows {
			for _, part := range Parts[name] {
				for _, op := range wk {
					if op.fn(part[op.part], op.val) {
						Parts[op.dest] = append(Parts[op.dest], part)
						break
					}
				}
			}
			Parts[name] = make([]Part, 0)
		}
	}

	ans := 0
	for _, p := range Parts["A"] {
		ans += p[0] + p[1] + p[2] + p[3]
	}
	fmt.Println("Ans:", ans)
}
