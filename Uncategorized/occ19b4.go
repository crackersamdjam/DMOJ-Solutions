package main
import "fmt"

var n, a, v int

func main(){
	fmt.Scanf("%d", &n)
	for i := 0; i < n; i++ {
		fmt.Scanf("%d", &v)
		a -= v
		if(v > a){
			a = v
		}
	}
	fmt.Println(a)
}