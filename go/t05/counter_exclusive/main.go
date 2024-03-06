package main

import (
	"fmt"
	"sync"
)

func main() {
	ch := make(chan int) //unbuffered channel
	var wg sync.WaitGroup

	for i := 0; i < 1000; i++ {
		wg.Add(1)
		go func() {
			count := <-ch // store value from channel, blocking dequeue
			count++
			wg.Done()
			ch <- count //blocking enqueue
		}()
	}
	ch <- 0 //set initial value; blocking enqueue
	wg.Wait()
	fmt.Println(<-ch)
}
