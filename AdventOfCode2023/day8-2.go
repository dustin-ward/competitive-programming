package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

type N struct {
	L string
	R string
}

func GCD(a, b int) int {
	for b != 0 {
		t := b
		b = a % b
		a = t
	}
	return a
}

func LCM(nums []int) int {
	ret := nums[0]

	for i := 1; i < len(nums); i++ {
		ret = (nums[i] * ret) / GCD(nums[i], ret)
	}

	return ret
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	instr, _ := reader.ReadString('\n')
	instr = instr[:len(instr)-1]
	_, _ = reader.ReadString('\n')

	Map := make(map[string]N, 0)
	As := make([]string, 0)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]

		s := strings.Split(line, " = ")
		name := s[0]
		s = strings.Split(s[1], ", ")
		Map[name] = N{
			s[0][1:],
			s[1][:3],
		}
		if name[2] == 'A' {
			As = append(As, name)
		}
	}

	dis := make([]int, len(As))
	for is, s := range As {
		cur := s
		i := 0
		for cur[2] != 'Z' {
			if instr[i%len(instr)] == 'R' {
				cur = Map[cur].R
			} else {
				cur = Map[cur].L
			}

			i++
		}
		dis[is] = i
	}

	fmt.Println("Ans:", LCM(dis))
}
