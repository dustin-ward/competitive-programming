package main

import (
	"bufio"
	"os"
)

func main() {
	reader := bufio.NewReader(os.Stdin)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
		}
		line = line[:len(line)-1]

		if line == "\n" {
			// Blank Line
		}
	}
}
