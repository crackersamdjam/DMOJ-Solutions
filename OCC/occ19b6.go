package main
import "fmt"

func main(){
	var n, b int
	fmt.Scanf("%d%d", &n, &b);
	if b % 2 == 1 {
		if n % 2 == 1 {
			fmt.Println("Modo")
		} else {
			fmt.Println("Winnie")
		}
	} else {
		if ((n % (b+1)) % 2) == 1 {
			fmt.Println("Modo")
		} else {
			fmt.Println("Winnie")
		}
	}
}