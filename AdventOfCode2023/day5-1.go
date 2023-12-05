package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"sort"
	"strconv"
	"strings"
)

type mapping struct {
	dest int
	orig int
	leng int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	// Seeds
	line, _ := reader.ReadString('\n')
	line = line[:len(line)-1]
	line = strings.Split(line, ": ")[1]
	seeds := strings.Split(line, " ")

	// Empty line
	line, _ = reader.ReadString('\n')

	maps := make([][]mapping, 0)

	// Map
	done := false
	for {
		// Name
		line, _ = reader.ReadString('\n')

		// Mapping
		curMaps := make([]mapping, 0)
		for {
			// nums
			line, err := reader.ReadString('\n')
			if err != nil || line == "\n" {
				//EOF
				done = err == io.EOF
				break
			}
			line = line[:len(line)-1]

			M := mapping{}
			fmt.Sscanf(line, "%d %d %d", &M.dest, &M.orig, &M.leng)
			curMaps = append(curMaps, M)
		}

		sort.Slice(curMaps, func(i, j int) bool {
			return curMaps[i].orig < curMaps[j].orig
		})
		maps = append(maps, curMaps)

		if done {
			break
		}
	}

	ans := (1 << 62) - 1
	for _, seed := range seeds {
		x, _ := strconv.Atoi(seed)
		for _, m := range maps {
			i := 0
			for ; i < len(m); i++ {
				if x >= m[i].orig && x < m[i].orig+m[i].leng {
					break
				}
			}
			if i != len(m) {
				x = m[i].dest + (x - m[i].orig)
			}
		}
		ans = min(ans, x)
	}

	fmt.Println("Ans:", ans)
}
