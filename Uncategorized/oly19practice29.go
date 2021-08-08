package main
import "fmt"

func gcd(gcd_a, gcd_b int) int{
	if gcd_b == 0 {
		return gcd_a
	}
	return gcd(gcd_b, gcd_a % gcd_b)
}

func main(){
	var x, y, z int
	fmt.Scanf("%d%d%d", &x, &y, &z)
	x %= y
	if x == 0 && z != 0 {
		fmt.Println("NO")
	} else if z % gcd(x, y) == 0 {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}