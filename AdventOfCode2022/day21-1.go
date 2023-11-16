package main

import (
    "fmt"
    "io"
    "strconv"
)

type expr struct {
    lhs string
    op string
    rhs string
}

var inpt map[string]expr
var lookup map[string]int

func f(m string) int {
    if v, ok := lookup[m]; ok {
        return v
    }

    e := inpt[m]
    switch(e.op) {
        case "+":
            lookup[m] = f(e.lhs) + f(e.rhs)
        case "-":
            lookup[m] = f(e.lhs) - f(e.rhs)
        case "*":
            lookup[m] = f(e.lhs) * f(e.rhs)
        case "/":
            lookup[m] = f(e.lhs) / f(e.rhs)
    }
    return lookup[m]
}

func main() {
    inpt = make(map[string]expr)
    lookup = make(map[string]int)
    for {
        var name, lhs, op, rhs string
        n, err := fmt.Scanf("%s %s %s %s", &name, &lhs, &op, &rhs)
        if err == io.EOF {
            break
        }
        name = name[:len(name)-1]
        
        // fmt.Println("n", n)
        // fmt.Println("name", name, "lhs", lhs, "op", op, "rhs", rhs)

        inpt[name] = expr{lhs,op,rhs}
        if n == 2 {
            v, err := strconv.Atoi(lhs)
            if err != nil {
                panic(err)
            }
            lookup[name] = v
        }
    }
    // fmt.Println(inpt)
    // fmt.Println(lookup)

    fmt.Println("Ans:", f("root"))
}
