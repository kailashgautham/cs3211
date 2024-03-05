//idiomatic declaration - size 0, capacity 5
s := make([]int, 0, 5)

for i := 0; i < 5; i++ {
	s = append(s, 0)            // add 0 to slice
	fmt.Println(len(s), cap(s)) // size +1 from before, underlying capacity unchanged
}

for i := 0; i < 5; i++ {
	s = append(s, 0)            // add 0 to slice; first append after running out of capacity allocates x2 memory; capacity is 10 now
	fmt.Println(len(s), cap(s)) // size +1 before, cap unchanged after doubling
}