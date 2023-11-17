package main

import (
    "fmt"
    "os"
    "bufio"
    "strconv"
)

type pii struct {
    fst int
    snd int
}

func main() {
    B := make([]string,0)
    in := bufio.NewReader(os.Stdin)
    var M int
    for {
        line, _ := in.ReadString('\n')
        if line == "\n" {
            break
        }

        line = line[:len(line)-1]
        line = " "+line+" "
        M = max(M, len(line))
        B = append(B, line)
    }
    r := make([]rune,M)
    for i:=0; i<M; i++ {
        r[i] = rune(' ')
    }
    blank:= string(r)
    B = append([]string{blank}, B...)
    B = append(B, blank)
    N := len(B)

    for i:=0; i<N; i++ {
        for len(B[i]) != M {
            B[i] += " "
        }
    }

    inst, _ := in.ReadString('\n')
    inst = inst[:len(inst)-1]

    fmt.Println(len(B))
    for i,s := range B {
        fmt.Println(i,":", s, len(s))
    }
    // fmt.Println(B)
    // fmt.Println(inst)

    var pos pii
    for i:=0; i<M; i++ {
        if B[1][i] == byte('.') {
            pos = pii{1,i}
            break
        }
    }

    dy := []int{0, 1, 0, -1}
    dx := []int{1, 0, -1, 0}
    dir := 0
    
    for len(inst) > 0 {
        if inst[0] == 'R' || inst[0] == 'L' {
            if inst[0] == 'R' {
                dir = (dir+1)%4
            } else {
                dir = (dir+3)%4
            }

            inst = inst[1:]
        } else {
            i:=0
            for i<len(inst) && !(inst[i] == 'R' || inst[i] == 'L') {
                i++
            }

            dis, _ := strconv.Atoi(inst[:i])
            for i:=0; i<dis; i++ {
                i2 := pos.fst+dy[dir]
                j2 := pos.snd+dx[dir]
                if B[i2][j2] == byte(' ') {
                    op := (dir+2)%4
                    i2 += dy[op]
                    j2 += dx[op]
                    for B[i2][j2] != byte(' ') {
                        i2 += dy[op]
                        j2 += dx[op]
                    }
                    i2 += dy[dir]
                    j2 += dx[dir]
                }
                if B[i2][j2] == byte('#') {
                    continue
                }

                pos = pii{i2,j2}
            }

            inst = inst[i:]
        }
    }

    fmt.Println("POS:", pos)
    ans := 1000 * pos.fst + 4 * pos.snd + dir
    fmt.Println("ANS:", ans)
}
