package main

import (
	"fmt"
	"sync"
	"time"
)

var (
	hello = "Hello"
	world = "World"
)

func printHello() {
	time.Sleep(time.Second)
	fmt.Println(hello)
}

func main() {

	world := "World"             //preferred
	var exclamation string = "!" //not preferred
	var wg sync.WaitGroup        //wg is initialised as a WaitGroup
	wg.Add(2)                    //adds two to the wg counter

	go func() {
		//defer statements run after the function exits
		defer wg.Done() //decrements the counter by 1
		printHello()
	}()
	go func(name string) {
		defer wg.Done()
		time.Sleep(2 * time.Second)
		name += exclamation
		fmt.Println(name)
	}(world) //world is the parameter

	wg.Wait() //waits for the counter to reach 0
}
