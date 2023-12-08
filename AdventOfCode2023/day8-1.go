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

func main() {
	reader := bufio.NewReader(os.Stdin)
	instr, _ := reader.ReadString('\n')
	instr = instr[:len(instr)-1]
	_, _ = reader.ReadString('\n')

	Map := make(map[string]N, 0)
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
	}

	cur := "AAA"

	i := 0
	for cur != "ZZZ" {
		if instr[i%len(instr)] == 'R' {
			cur = Map[cur].R
		} else {
			cur = Map[cur].L
		}

		i++
	}

	fmt.Println("Ans:", i)
}
