package main

import (
	"fmt"
	"time"
)

func producer(done chan struct{}, q chan<- int) {
	for {
		select {
		case q <- 1: // keeps incrementing...
		case <-done: // until stopped (channel closed)
			return
		}
	}
}

func consumer(q <-chan int) {
	// TODO consume from q
	// TODO send local sum on close
}

var (
	NumProducer = 5
	NumConsumer = 5
)

func main() {
	done := make(chan struct{})
	q := make(chan int)

	for i := 0; i < NumProducer; i++ {
		go producer(done, q)
	}

	// TODO spawn consumers
	for i := 0; i < NumConsumer; i++ {
		go consumer(q)
	}

	time.Sleep(time.Second) // run for 1 second
	close(done)             // stop all producers and consumers

	// TODO merge into global sum
	sum := 0
	fmt.Println("Sum: ", sum)
}
