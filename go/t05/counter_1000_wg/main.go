package main

import (
	"fmt"
	"sync"
)

// data race as multiple goroutines are incrementing count at the same time
func main() {
	count := 0
	var wg sync.WaitGroup
	for i := 0; i < 1000; i++ {
		wg.Add(1)
		go func() {
			defer wg.Done()
			count++
		}()
	}
	wg.Wait()
	fmt.Println(count)
}
