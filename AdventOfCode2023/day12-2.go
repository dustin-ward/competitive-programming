package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

var sizes []int
var str []rune
var DP [][][]int

func f(i int, m int, passed int) int {
	if i == len(str) {
		if (m == len(sizes) && passed == 0) || (m == len(sizes)-1 && passed == sizes[m]) {
			return 1
		} else {
			return 0
		}
	}
	if DP[i][m][passed] != -1 {
		return DP[i][m][passed]
	}

	ans := 0
	if str[i] == '#' || str[i] == '?' {
		ans += f(i+1, m, passed+1)
	}
	if str[i] == '.' || str[i] == '?' {
		if passed > 0 && m < len(sizes) && passed == sizes[m] {
			ans += f(i+1, m+1, 0)
		} else if passed == 0 {
			ans += f(i+1, m, 0)
		}
	}

	DP[i][m][passed] = ans
	return ans
}

func main() {
	ans := 0
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]

		s := strings.Split(line, " ")
		s2 := strings.Split(s[1], ",")
		str = []rune(s[0] + "?" + s[0] + "?" + s[0] + "?" + s[0] + "?" + s[0])
		sizes = make([]int, 0)
		for _, str := range s2 {
			if str != "" {
				x, _ := strconv.Atoi(str)
				sizes = append(sizes, x)
			}
		}
		x := len(sizes)
		for i := 0; i < 4; i++ {
			sizes = append(sizes, sizes[:x]...)
		}

		DP = make([][][]int, len(str)+1)
		for i, _ := range DP {
			DP[i] = make([][]int, len(sizes)+1)
			for j, _ := range DP[i] {
				DP[i][j] = make([]int, len(str)+1)
				for k, _ := range DP[i][j] {
					DP[i][j][k] = -1
				}
			}
		}

		temp := f(0, 0, 0)
		fmt.Println(s[0], sizes)
		fmt.Println("=", temp)
		ans += temp
	}
	fmt.Println("Ans:", ans)
}
