package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	reader := bufio.NewReader(os.Stdin)

	line, _ := reader.ReadString('\n')
	line = line[:len(line)-1]
	s := strings.Split(line, ": ")
	s = strings.Split(s[1], " ")
	times := make([]int, 0)
	for _, str := range s {
		if str != "" {
			x, _ := strconv.Atoi(str)
			times = append(times, x)
		}
	}
	line, _ = reader.ReadString('\n')
	line = line[:len(line)-1]
	s = strings.Split(line, ": ")
	s = strings.Split(s[1], " ")
	dist := make([]int, 0)
	for _, str := range s {
		if str != "" {
			x, _ := strconv.Atoi(str)
			dist = append(dist, x)
		}
	}

	ans := 1
	for r := 0; r < len(times); r++ {
		cnt := 0
		for t := 0; t <= times[r]; t++ {
			dis := (times[r] - t) * t
			if dis > dist[r] {
				cnt++
			}
		}
		ans *= cnt
	}

	fmt.Println("Ans:", ans)
}
