package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var N, M int

type Part struct {
	num string
	i   int
	j   int
}

func bounds(i, j int) bool {
	return i >= 0 && i < N && j >= 0 && j < M
}

func partSym(c rune) bool {
	return (c < '0' || c > '9') && c != '.'
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
		B = append(B, line)
	}

	N = len(B)
	M = len(B[0]) - 1
	nums := make([]Part, 0)
	curNum := ""
	for i := 0; i < N; i++ {
		for j := 0; j < M; j++ {
			inNum := curNum != ""
			c := rune(B[i][j])
			if c >= '0' && c <= '9' {
				curNum += string(B[i][j])
			} else {
				if inNum {
					nums = append(nums, Part{
						curNum,
						i,
						j - len(curNum),
					})
					curNum = ""
				}
			}
		}
		if curNum != "" {
			nums = append(nums, Part{
				curNum,
				i,
				M - len(curNum),
			})
			curNum = ""
		}
	}

	sum := 0
	for _, p := range nums {
		part := false
		for i := p.i - 1; i <= p.i+1; i++ {
			for j := p.j - 1; j <= p.j+len(p.num); j++ {
				if bounds(i, j) {
					fmt.Printf("%s", B[i][j:j+1])
				}
				if bounds(i, j) && partSym(rune(B[i][j])) {
					part = true
				}
			}
			fmt.Printf("\n")
		}

		if part {
			x, _ := strconv.Atoi(p.num)
			sum += x
		}
	}

	println("Ans:", sum)
}
