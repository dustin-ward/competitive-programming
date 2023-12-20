package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

const CATS = "xmas"

type Part [2][4]int

const (
	L = 0
	U = 1
)

type Op struct {
	part int
	val  int
	op   string
	dest string
}

var Workflows map[string][]Op

func f(name string, part Part) int {
	if name == "A" {
		sum := 1
		for i := 0; i < 4; i++ {
			dif := part[1][i] - part[0][i] + 1
			if dif > 0 {
				sum *= dif
			}
		}
		return sum
	} else if name == "R" {
		return 0
	}

	ans := 0
	for _, op := range Workflows[name] {
		cut_part := part
		switch op.op {
		case "<":
			cut_part[U][op.part] = op.val - 1
			part[L][op.part] = op.val
		case ">":
			cut_part[L][op.part] = op.val + 1
			part[U][op.part] = op.val
		default:

		}

		ans += f(op.dest, cut_part)
	}
	return ans
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	Workflows = make(map[string][]Op)

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

		line = line[idx+1 : len(line)-1]
		ops := strings.Split(line, ",")
		for _, s := range ops {
			idx2 := strings.Index(s, ":")
			if idx2 != -1 {
				dest := s[idx2+1:]
				s = s[:idx2]
				p := s[0]
				op := s[1]
				val, _ := strconv.Atoi(s[2:])
				Workflows[name] = append(Workflows[name], Op{
					strings.Index(CATS, string(p)),
					val,
					string(op),
					dest,
				})
			} else {
				Workflows[name] = append(Workflows[name], Op{
					0,
					0,
					"",
					s,
				})
			}
		}
	}

	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			break
		}
		line = line[:len(line)-1]
	}

	ans := 0
	ans += f("in", Part{{1, 1, 1, 1}, {4000, 4000, 4000, 4000}})
	fmt.Println("Ans:", ans)
}
