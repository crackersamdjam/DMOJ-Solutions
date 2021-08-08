package main;

import (
"fmt"
"math"
)

func main(){
	var n, m, a, b int
	fmt.Scanf("%d %d %d %d", &n, &m, &a, &b)
	fmt.Printf("%.6f", math.Sqrt(float64(n*n*b*b + m*m*a*a)))
}