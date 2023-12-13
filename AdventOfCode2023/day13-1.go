package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func reverse(str string) (result string) {
	for _, v := range str {
		result = string(v) + result
	}
	return
}

func trans(b []string) []string {
	N := len(b)
	M := len(b[0])

	b2 := make([]string, 0)
	for j := 0; j < M; j++ {
		str := make([]rune, N)
		for i := 0; i < N; i++ {
			str[i] = rune(b[i][j])
		}
		b2 = append(b2, string(str))
	}
	return b2
}

func mirror(B []string) int {
	N := len(B)
	M := len(B[0])

	mp := make([]int, M)
	for i := 1; i < M-1; i++ {
		mp[i] = i
	}
	for i := 0; i < N && len(mp) > 0; i++ {
		j := 0
		for j < len(mp) {
			x := mp[j]
			s1 := reverse(B[i][:x+1])
			s2 := B[i][x+1:]
			if !(strings.HasPrefix(s1, s2) || strings.HasPrefix(s2, s1)) {
				mp = append(mp[:j], mp[j+1:]...)
				j--
			}
			j++
		}
	}

	if len(mp) != 0 {
		return mp[0] + 1
	}
	return 0
}

func solve(B []string) (int, int) {
	numCols := mirror(B)
	B = trans(B)
	numRows := mirror(B)
	return numCols, numRows
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	B := make([]string, 0)
	numCols := 0
	numRows := 0
	for {
		line, err := reader.ReadString('\n')
		if err != nil || line == "\n" {
			i, j := solve(B)
			numCols += i
			numRows += j
			B = make([]string, 0)
			if err != nil {
				break
			}
		} else {
			line = line[:len(line)-1]
			B = append(B, line)
		}
	}

	fmt.Println("Ans:", numCols+(numRows*100))
}
