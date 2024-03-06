package main

import (
	"fmt"
)

func main() {
	count := 0
	go func() {
		count++
	}()
	go func() {
		count++
	}()
	fmt.Println(count)

}
