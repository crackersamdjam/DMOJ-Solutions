package main
import "fmt"
func main(){
	var n int
	fmt.Scanf("%d", &n)
	if n % 4 == 0 || n % 4 == 3 {
		fmt.Println("Yes")
	}else{
		fmt.Println("No")
	}
}