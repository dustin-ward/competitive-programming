package main

import (
    "math"
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
    
    var B [4]string
    for i:=0; i<4; i++ {
        scanf("%s\n", &B[i])
    }

    pos := map[byte]struct{y,x int}{
        byte('A'): {0,0},
        byte('B'): {0,1},
        byte('C'): {0,2},
        byte('D'): {0,3},
        byte('E'): {1,0},
        byte('F'): {1,1},
        byte('G'): {1,2},
        byte('H'): {1,3},
        byte('I'): {2,0},
        byte('J'): {2,1},
        byte('K'): {2,2},
        byte('L'): {2,3},
        byte('M'): {3,0},
        byte('N'): {3,1},
        byte('O'): {3,2},
    }

    ans := 0
    for i:=0; i<4; i++ {
        for j:=0; j<4; j++ {
            if B[i][j] == byte('.') {
                continue
            }
            // printf("CHAR: %s\n", string(B[i][j]))
            p := pos[B[i][j]]
            dis := int(math.Abs(float64(p.y-i))) + int(math.Abs(float64(p.x-j)))
            // printf("DIS: %v\n", dis)
            ans += dis
        }
    }
    printf("%d\n", ans)
}
