//go can return multiple values from a function
package main 

func request() (Response, error) {
    if timeout() {
        return nil, fmt.Errorf("timeout")
    }
    return resp, nil
}
// ...
resp, err := request()
// Very common to see lots of `if err != nil` calls everywhere
if err != nil {
    // handle err or propagate it to the caller
    return nil, err
}