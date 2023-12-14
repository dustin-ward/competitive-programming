package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

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

func main() {
	reader := bufio.NewReader(os.Stdin)
	B := make([]string, 0)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]
		B = append(B, line)
	}
	B = trans(B)
	M := len(B[0])

	ans := 0
	for _, line := range B {
		secs := strings.Split(line, "#")
		newline := ""
		for _, s := range secs {
			x := strings.Count(s, "O")
			newline += strings.Repeat("O", x) + strings.Repeat(".", len(s)-x) + "#"
		}
		for i, c := range newline {
			if c == 'O' {
				ans += M - i
			}
		}
	}
	fmt.Println("Ans:", ans)
}
