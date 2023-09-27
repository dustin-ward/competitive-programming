package main

import (
	"bufio"
	"fmt"
	"os"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func main() {
	defer writer.Flush()
    var N int
    scanf("%d\n", &N)

    sumM := 0.0
    sumS := 0.0
    for i:=0; i<N; i++ {
        var M,S float64
        scanf("%f %f\n", &M, &S)
        sumM += M
        sumS += S
    }

    avg := sumS / sumM
    if avg <= 60 {
        printf("measurement error\n")
    } else {
        printf("%.10f\n", avg/60.0)
    }
}
