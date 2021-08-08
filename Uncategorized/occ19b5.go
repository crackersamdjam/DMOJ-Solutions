package main

import (
	"fmt"
	"sort"
)

var x, y, z, n, v int
var a[]int

func main(){
	fmt.Scanf("%d%d%d%d", &x, &y, &z, &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &v)
		a = append(a, v)
	}
	sort.Ints(a)
	ans := int64(0)
	for i := 0; i < n; i++ {
		if z > 0 {
			nv := int64(x/(n+1-i))*int64(y) + int64(z)
			if nv > ans {
				ans = nv
			}
		}
		z -= a[i]
	}
	if z > 0 {
		t := int64(z+x*y)
		if t > ans {
			ans = t
		}
	}
	fmt.Println(ans)
}