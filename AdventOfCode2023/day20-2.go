package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func GCD(a, b int) int {
	for b != 0 {
		t := b
		b = a % b
		a = t
	}
	return a
}

func LCM(nums []int) int {
	ret := nums[0]

	for i := 1; i < len(nums); i++ {
		ret = (nums[i] * ret) / GCD(nums[i], ret)
	}

	return ret
}

const PRESSES = 15000

type Signal int

const (
	LO Signal = iota
	HI
)

type Event struct {
	orig string
	dest string
	sig  Signal
}

var EVENT_Q []Event

type Gate interface {
	Update(string, Signal)
	AddOutput(string)
}

type FlipFlop struct {
	name    string
	on      bool
	outputs []string
}

func (f *FlipFlop) Update(inpt string, sig Signal) {
	if sig == LO {
		f.on = !f.on
	} else {
		return
	}

	for _, output := range f.outputs {
		var newSig Signal = LO
		if f.on {
			newSig = HI
		}

		EVENT_Q = append(EVENT_Q, Event{f.name, output, newSig})
	}
}

func (f *FlipFlop) AddOutput(out string) {
	f.outputs = append(f.outputs, out)
}

type Conjunction struct {
	name    string
	inputs  map[string]Signal
	outputs []string
}

func (c *Conjunction) Update(inpt string, sig Signal) {
	c.inputs[inpt] = sig

	newSig := LO
	for _, v := range c.inputs {
		if v == LO {
			newSig = HI
			break
		}
	}

	for _, output := range c.outputs {
		EVENT_Q = append(EVENT_Q, Event{c.name, output, newSig})
	}
}
func (c *Conjunction) AddOutput(out string) {
	c.outputs = append(c.outputs, out)
}

type Broadcaster struct {
	name    string
	outputs []string
}

func (b *Broadcaster) Update(inpt string, sig Signal) {
	for _, output := range b.outputs {
		EVENT_Q = append(EVENT_Q, Event{b.name, output, sig})
	}
}

func (b *Broadcaster) AddOutput(out string) {
	b.outputs = append(b.outputs, out)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	GATE := make(map[string]Gate)
	conj := make(map[string]bool)
	for {
		line, err := reader.ReadString('\n')
		if err != nil {
			//EOF
			break
		}
		line = line[:len(line)-1]

		s := strings.Split(line, " -> ")
		name := s[0]
		outps := strings.Split(s[1], ", ")

		if name[0] != 'b' {
			ch := name[0]
			name = name[1:]
			if ch == '%' {
				GATE[name] = &FlipFlop{name, false, make([]string, 0)}
			} else if ch == '&' {
				GATE[name] = &Conjunction{name, make(map[string]Signal), make([]string, 0)}
				conj[name] = true
			}
		} else {
			GATE[name] = &Broadcaster{name, make([]string, 0)}
		}

		for _, output := range outps {
			GATE[name].AddOutput(output)
		}
	}

	// Add Conjunction inputs
	// Bad hack
	for k, v := range GATE {
		var outputs *[]string
		switch g_orig := v.(type) {
		case *FlipFlop:
			outputs = &g_orig.outputs
		case *Conjunction:
			outputs = &g_orig.outputs
		case *Broadcaster:
			outputs = &g_orig.outputs
		default:
			panic("I dont know what im doing")
		}

		for _, output := range *outputs {
			if g, ok := GATE[output].(*Conjunction); ok {
				g.inputs[k] = LO
			}
		}
	}

	EVENT_Q = make([]Event, 0, 1024)

	// rx <- &cn
	//
	// &cn <- &ch, &gh, &sv, &th
	cycles := make(map[string][]int)
	cycles["ch"] = make([]int, 0)
	cycles["gh"] = make([]int, 0)
	cycles["sv"] = make([]int, 0)
	cycles["th"] = make([]int, 0)
	for press := 1; press < PRESSES; press++ {
		EVENT_Q = append(EVENT_Q, Event{"button", "broadcaster", LO})

		for len(EVENT_Q) > 0 {
			e := EVENT_Q[0]
			EVENT_Q = EVENT_Q[1:]

			if _, ok := cycles[e.orig]; ok && e.sig == HI {
				cycles[e.orig] = append(cycles[e.orig], press)
			}

			if g, ok := GATE[e.dest]; ok {
				g.Update(e.orig, e.sig)
			}
		}
	}

	fmt.Println("Cycles:", cycles)
	fmt.Println("Ans:", LCM([]int{cycles["ch"][0], cycles["gh"][0], cycles["sv"][0], cycles["th"][0]}))
}
