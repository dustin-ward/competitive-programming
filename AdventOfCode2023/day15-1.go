package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func hash(str string) int {
	cur := 0
	for _, c := range str {
		cur += int(c)
		cur *= 17
		cur %= 256
	}
	return cur
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	ans := 0
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]

		for _, s := range strings.Split(line, ",") {
			ans += hash(s)
		}
	}

	fmt.Println("Ans:", ans)
}
