package main
import "fmt"

var x1, x2, x3, x4, y1, y2, y3, y4 int

func min(x, y int) int{
	if x > y {
		return y
	}
	return x
}

func max(x, y int) int{
	if x < y {
		return y
	}
	return x
}

func main() {

	fmt.Scanf("%d%d%d%d\n%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4)
	if x1 > x2 {
		x1, x2 = x2, x1
	}
	if y1 > y2 {
		y1, y2 = y2, y1
	}
	if x3 > x4 {
		x3, x4 = x4, x3
	}
	if y3 > y4 {
		y3, y4 = y4, y3
	}

	fmt.Println((x2-x1)*(y2-y1) + (x4-x3)*(y4-y3) - max(0, min(x2, x4)-max(x1, x3))*max(0, (min(y2, y4)-max(y1, y3))))
}