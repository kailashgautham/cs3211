// traditional if-else
// initialising
res, err := doSomething()
if err != nil {
    // handle err or
} else {
    // do something with res
}

// shorthand
//creating
if res, err := doSomething(); err != nil {
    // handle err or
} else {
    // do something with res
}

// overwriting existing variables
var res, err
if res, err = doSomething(); err != nil {
    // handle err or
} else {
    // do something with res
}