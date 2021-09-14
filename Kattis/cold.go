package main

import "fmt"

func main() {
	var n int

	fmt.Scanln(&n)

	ans := 0
	for i := 0; i < n; i++ {
		var temp int
		fmt.Scanf("%d", &temp)
		if temp < 0 {
			ans++
		}
	}

	fmt.Println(ans)
}
