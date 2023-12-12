package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var sizes []int
var M map[string]bool

func f(str []rune, i int) int {
	if i == len(str) {
		if _, ok := M[string(str)]; ok {
			return 0
		}

		s := strings.Split(string(str), ".")
		groups := make([]string, 0)
		for _, s2 := range s {
			if s2 != "" {
				groups = append(groups, s2)
			}
		}

		good := len(groups) == len(sizes)
		if good {
			for i, x := range sizes {
				if len(groups[i]) != x {
					good = false
					break
				}
			}
		}

		M[string(str)] = true
		if good {
			return 1
		} else {
			return 0
		}
	}

	sum := 0
	if str[i] == '?' {
		str[i] = '#'
		sum += f(str, i+1)
		str[i] = '.'
		sum += f(str, i+1)
		str[i] = '?'
	} else {
		sum += f(str, i+1)
	}
	return sum
}

func main() {
	ans := 0
	reader := bufio.NewReader(os.Stdin)
	for {
		M = make(map[string]bool, 0)
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]

		s := strings.Split(line, " ")
		s2 := strings.Split(s[1], ",")
		sizes = make([]int, 0)
		for _, str := range s2 {
			if str != "" {
				x, _ := strconv.Atoi(str)
				sizes = append(sizes, x)
			}
		}

		ans += f([]rune(s[0]), 0)
	}
	fmt.Println("Ans:", ans)
}
