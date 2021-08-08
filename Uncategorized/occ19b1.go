package main
import (
	"fmt"
	"strings"
)
var s string
func main(){
	fmt.Scanf("%s", &s)
	if s := strings.ToLower(s); s == "darcy_liu" {
		fmt.Println("real")
	} else if len(s) >= 9 && strings.HasPrefix(s, "darcy") && strings.HasSuffix(s, "liu") {
		for i := 5; i < len(s)-3; i++ {
			if s[i] != '_' {
				fmt.Println("other user")
				return
			}
		}
		fmt.Println("fake")
	} else {
		fmt.Println("other user")
	}
}