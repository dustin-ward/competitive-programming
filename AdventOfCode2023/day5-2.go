package main

import (
	"bufio"
	"fmt"
	"io"
	"os"
	"slices"
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

	slices.Reverse(maps)
	for x := 1; x < (1 << 62); x++ {
		y := x
		for _, m := range maps {
			i := 0
			for ; i < len(m); i++ {
				if y >= m[i].dest && y < m[i].dest+m[i].leng {
					break
				}
			}
			if i != len(m) {
				y = m[i].orig + (y - m[i].dest)
			}
		}

		for s := 0; s < len(seeds); s += 2 {
			i, _ := strconv.Atoi(seeds[s])
			l, _ := strconv.Atoi(seeds[s+1])
			if y > i && y < i+l {
				fmt.Println("Ans:", x)
				os.Exit(0)
			}
		}
	}
}
