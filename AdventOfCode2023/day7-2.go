package main

import (
	"bufio"
	"fmt"
	"os"
	"sort"
	"strings"
)

const CARDS = "J23456789TQKA"

func handRank(hand string) int {
	m := make(map[rune]int, 0)
	j := 0
	for _, ch := range hand {
		if ch == 'J' {
			j++
			continue
		}
		m[ch]++
	}

	if len(m) == 1 || len(m) == 0 {
		return 18
	}
	if len(m) == 2 {
		for _, v := range m {
			if v == 4 || v+j == 4 {
				return 17
			}
		}
		return 16
	}
	if len(m) == 3 {
		for _, v := range m {
			if v == 3 || v+j == 3 {
				return 15
			}
		}
		return 14
	}
	if len(m) == 4 {
		return 13
	}

	return 12
}

type P struct {
	hand string
	bet  int
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	players := make([]P, 0)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			break
		}
		line = line[:len(line)-1]

		var hand string
		var bet int
		fmt.Sscanf(line, "%s %d", &hand, &bet)
		players = append(players, P{
			hand,
			bet,
		})
	}

	sort.Slice(players, func(i, j int) bool {
		s1 := handRank(players[i].hand)
		s2 := handRank(players[j].hand)
		if s1 == s2 {
			for k := 0; k < 5; k++ {
				c1 := strings.IndexRune(CARDS, rune(players[i].hand[k]))
				c2 := strings.IndexRune(CARDS, rune(players[j].hand[k]))
				if c1 == c2 {
					continue
				} else {
					return c1 < c2
				}
			}
		}
		return s1 < s2
	})

	ans := 0
	for i := 1; i <= len(players); i++ {
		ans += players[i-1].bet * i
	}
	fmt.Println("ans:", ans)
}
