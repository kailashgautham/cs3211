package main

import (
	"fmt"
	"sync"
)

func main() {
	count := 0
	var wg sync.WaitGroup
	wg.Add(2)
	go func() {
		defer wg.Done()
		count++
	}()
	go func() {
		defer wg.Done()
		count++
	}()
	wg.Wait()
	fmt.Println(count)

}
