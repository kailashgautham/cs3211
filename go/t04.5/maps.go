m1 := make(map[string]int) //m1 is a map from strings to ints

m2 = map[string]int{} //m2 is a map from strings to ints

m3 = map[string]int{
	"one":   1,
	"two":   2,
	"three": 3,
} //m3 is a map from strings to ints

val := m1[key1] //like C++ - if key1 does not exist, val is the zero value for the map's value type

val, ok = m1[key1] //ok is true if key1 exists in m1, false otherwise
