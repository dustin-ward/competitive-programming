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
var parent map[string]string

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
        case "=":
            lookup[m] = 0
    }
    return lookup[m]
}

func main() {
    inpt = make(map[string]expr)
    lookup = make(map[string]int)
    parent = make(map[string]string)
    for {
        var name, lhs, op, rhs string
        n, err := fmt.Scanf("%s %s %s %s", &name, &lhs, &op, &rhs)
        if err == io.EOF {
            break
        }
        name = name[:len(name)-1]
        
        e := expr{lhs,op,rhs}
        if name == "root" {
            e.op = "="
        }
        inpt[name] = e
        if n == 2 {
            v, err := strconv.Atoi(lhs)
            if err != nil {
                panic(err)
            }
            lookup[name] = v
        } else {
            parent[lhs] = name
            parent[rhs] = name
        }
    }
    f(inpt["root"].lhs)
    f(inpt["root"].rhs)

    stack := make([]string,1)
    str := "humn"
    for str != "root" {
        stack = append([]string{str}, stack...)
        str = parent[str]
    }
    stack = append([]string{"root"}, stack...)

    var need int
    for len(stack) > 1 {
        cur := inpt[stack[0]]
        stack = stack[1:]

        if stack[0] == cur.lhs {
            switch(cur.op) {
                case "=":
                    need = lookup[cur.rhs]
                case "+":
                    need = need - lookup[cur.rhs]
                case "-":
                    need = need + lookup[cur.rhs]
                case "*":
                    need = need / lookup[cur.rhs]
                case "/":
                    need = need * lookup[cur.rhs]
            }
        } else if stack[0] == cur.rhs {
            switch(cur.op) {
                case "=":
                    need = lookup[cur.lhs]
                case "+":
                    need = need - lookup[cur.lhs]
                case "-":
                    need = lookup[cur.lhs] - need
                case "*":
                    need = need / lookup[cur.lhs]
                case "/":
                    need = lookup[cur.lhs] / need
            }
        }
    }
    fmt.Println("Ans:", need)
}
