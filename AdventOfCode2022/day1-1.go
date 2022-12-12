package main

import (
	"bufio"
	"fmt"
	"os"
    "strconv"
    "sort"
)

var reader *bufio.Reader = bufio.NewReader(os.Stdin)
var writer *bufio.Writer = bufio.NewWriter(os.Stdout)

func printf(f string, a ...interface{}) { fmt.Fprintf(writer, f, a...) }
func scanf(f string, a ...interface{})  { fmt.Fscanf(reader, f, a...) }

func main() {
	defer writer.Flush()
    
    var line string
    V := make([]int, 1)
    V[0] = 0
    for scanf("%s\n" &line) {
        if line == "" {
            V = append(V, 0)
        } else {
            x, _ := strconv.Atoi(line)
            V[len(V)-1] += x
        }
    }

    sort.Sort(sort.Reverse(V))
    printf("%d\n", V[0])
}
