package main

import "fmt"

func main() {
	var X, N int
	fmt.Scanf("%d\n%d", &X, &N)
	ans := X
	for i := 0; i < N; i++ {
		var P int
		fmt.Scanf("%d", &P)
		ans += X - P
	}
	fmt.Println(ans)
}
