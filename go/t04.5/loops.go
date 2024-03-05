for i := 0; i < 5; i++ {
	// ...
}

// loop while check() is true
for check() {

}

// loop while check() is true
for {
	if ok := check(); !ok {
		break
	}
}

for i := range []int{1, 2, 3} {

}

for i, elem := range []int{1, 2, 3} {

}

// for unused index
for _, elem := range []int{1, 2, 3} {

}

// to use the value of i in the goroutine, we need to create a new variable (shadowing)
for i := range []int{1, 2, 3} {
	i := i // shadow i to snapshot the value i
	go func() {
		fmt.Println(i)
	}()
}

for k, v := range map[int]int{1: 1, 2: 2} {
	fmt.Println(k, v)
}

// reads from channel until no more elements and is closed
for elem := range elemCh {

}

// DOES NOT FALLTHROUGH BY DEFAULT
switch num {
case 1:
	// ...
case 2:
	// ...
	fallthrough
}
