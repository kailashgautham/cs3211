package main

import "fmt"

type Duck interface {
	Walk()
	Quack()
}

type Wing struct {
}

type SomeBird struct {
	wing Wing
}

func (w *Wing) Flap() {
	fmt.Println("Flap")
}

func (b *SomeBird) Walk() {
	fmt.Println("Walk")
}

func (b *SomeBird) Quack() {
	fmt.Println("Quack")
}

func (b *SomeBird) Fly() {
	b.wing.Flap()
	fmt.Println("Fly")
}

type Bird struct {
	CanFly bool
}

func (b Bird) AddWing1() {
	b.CanFly = true
}

func (b *Bird) AddWing2() {
	b.CanFly = true
}

func DuckWalksAndQuacks(d Duck) {
	d.Walk()
	d.Quack()
}

func main() {
	sb := &SomeBird{}
	sb.Walk()
	sb.Quack()
	sb.Fly()
	b := Bird{}
	//the receiver is a copy of the original object
	b.AddWing1()
	fmt.Println(b.CanFly) // false
	//the receiver is the actual object
	b.AddWing2()
	fmt.Println(b.CanFly) // true
	DuckWalksAndQuacks(sb)
}
