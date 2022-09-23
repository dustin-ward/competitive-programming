package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{}) (n int, err error) { return fmt.Fscanf(reader, f, a...) }

func Max(a,b int) int {
  if a >= b {
    return a
  } else {
    return b
  }
}

func main() {
	defer writer.Flush()

  for {
    var C,N int
    if n, err := scanf("%d %d\n", &C, &N); n == 0 || err != nil {
      break
    }

    W := make([]int, N+1)
    V := make([]int, N+1)
    W[0] = 0
    V[0] = 1

    for i:=1; i<=N; i++ {
      scanf("%d %d\n", &V[i], &W[i])
    }

    dp := make([][]int, N+1)
    for i:=0; i<=N; i++ {
      dp[i] = make([]int, C+1)
    }

    for i:=1; i<=N; i++ {
      for j:=1; j<=C; j++ {
        if W[i] <= j {
          dp[i][j] = Max(V[i] + dp[i-1][j-W[i]], dp[i-1][j])
        } else {
          dp[i][j] = dp[i-1][j]
        }
      }
    }
    
    var path []int
    j := C
    for i:=N; i>0; i-- {
      if dp[i][j] != dp[i-1][j] {
        path = append(path, i-1)
        j -= W[i]
      }
    }
    
    printf("%d\n", len(path))
    for _, i := range(path) {
      printf("%d ", i)
    }
    printf("\n")
  }
}
