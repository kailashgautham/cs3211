// package main

// import (
// 	"fmt"
// )

// func say123() {
// 	defer func() {
// 		fmt.Println(3)
// 	}()
// 	defer func() {
// 		fmt.Print(2)
// 	}()
// 	defer func() {
// 		fmt.Print(1)
// 	}()
// 	return
// }

// func main() {
// 	say123() // prints 123
// 	for k, v := range map[int]int{1: 1, 2: 2} {
// 		fmt.Println(k, v)
// 	}
// }
