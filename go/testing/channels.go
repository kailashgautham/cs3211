package main

import (
	"fmt"
	"runtime"
)

var c = make(chan int, 1)
var text string

func f() {
	text = "CS3211"
	<-c
}

func main() {
	fmt.Printf("no. cpu %d", runtime.NumCPU())
	go f()
	c <- 0
	fmt.Println(text)
}
