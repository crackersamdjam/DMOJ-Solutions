package main

import "fmt"
import "time"

func say() {
    time.Sleep(time.Millisecond * 999)
    fmt.Println("Hello, World!")
}

func main() {
    say()
}