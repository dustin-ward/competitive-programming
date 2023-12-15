package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
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

type lens struct {
	label string
	size  int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	ans := 0
	box := make([][]lens, 256)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]

		for _, s := range strings.Split(line, ",") {
			var label, op string
			var size int
			if s[len(s)-1] == '-' {
				op = "-"
				label = s[:len(s)-1]
			} else {
				size, _ = strconv.Atoi(s[len(s)-1:])
				op = "="
				label = s[:len(s)-2]
			}
			idx := hash(label)

			found := false
			for i, l := range box[idx] {
				if l.label == label {
					found = true
					if op == "-" {
						box[idx] = append(box[idx][:i], box[idx][i+1:]...)
						break
					} else {
						box[idx][i].size = size
					}
				}
			}
			if !found && op == "=" {
				box[idx] = append(box[idx], lens{
					label,
					size,
				})
			}
		}
	}

	for i, b := range box {
		for j, l := range b {
			ans += (i + 1) * (j + 1) * l.size
		}
	}

	fmt.Println("Ans:", ans)
}
