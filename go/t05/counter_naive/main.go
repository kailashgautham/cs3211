package main

import (
	"fmt"
	"time"
)

func main() {
	count := 0
	go func() {
		count++
	}()
	go func() {
		count++
	}()
	time.Sleep(time.Second / 1000000000)
	fmt.Println(count)

}
