package main
import "fmt"
func main(){
	var t int
	fmt.Scanf("%d", &t)
	for i := 0; i < t; i++ {
		var n int
		fmt.Scanf("%d", &n)
		var mp = make(map[int] int)
		ans := false
		for j := 1; j*j <= n; j++ {
			if n % j == 0 {
				mp[j + n/j] = 1
			}
		}
		for j := 1; j*j <= n; j++ {
			if n % j == 0 && mp[n/j - j] == 1 {
				ans = true
				break
			}
		}
		fmt.Print(n)
		if ans {
			fmt.Println(" is nasty")
		} else {
			fmt.Println(" is not nasty")
		}
	}
}