package main

import (
	"fmt"
    "io"
)

func abs(x int) int {
    if x < 0 {
        return -x
    } else {
        return x
    }
}

type Node struct {
    Val int
    Next *Node
    Prev *Node
}

func main() {
    inp := make([]*Node,0)
    N := 0
    var zero *Node
    for {
        var x int
        if _, err := fmt.Scanln(&x); err == io.EOF {
            break;
        }
        inp = append(inp, &Node{x,nil,nil})
        if x == 0 {
            zero = inp[N]
        }
        if N > 0 {
            inp[N-1].Next = inp[N]
            inp[N].Prev = inp[N-1]
        }
        N++

    }
    inp[N-1].Next = inp[0]
    inp[0].Prev = inp[N-1]

    for _, node := range inp {
        c := node.Val
        p := node
        if c == 0 {
            continue
        }
        if c<0 {
            c--
        }

        node.Prev.Next = node.Next
        node.Next.Prev = node.Prev

        for abs(c) > 0 {
            if c > 0 {
                p = p.Next
                c--
            } else {
                p = p.Prev
                c++
            }
        }

        node.Next = p.Next
        node.Prev = p
        p.Next.Prev = node
        p.Next = node
    }
    ans := 0
    for i:=0; i<=3000; i++ {
        if i % 1000 == 0{
            fmt.Println(i, zero.Val)
            ans += zero.Val
        }
        zero = zero.Next
    }
    fmt.Println(ans)
}
