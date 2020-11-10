package main

import (
	"fmt"
	"math"
)

func main() {
	triangleSquare(1, 2)
	triangleSquare(1, 1)
	triangleSquare(1, 3)

	/*
		给定正方形边长：  1
		给定正三角形边长：  2
		impossible!!!
			给定边长的正三角形不可以放在正方形内
		给定正方形边长：  1
		给定正三角形边长：  1
		possible...
		给定边长的正三角形可以放在正方形内
		给定正方形边长：  1
		给定正三角形边长：  3
		impossible!!!
			给定边长的正三角形不可以放在正方形内
	*/
}

func triangleSquare(squareLine, triangleLine float64) {

	fmt.Println("给定正方形边长： ", squareLine)
	fmt.Println("给定正三角形边长： ", triangleLine)

	t := 75.0 / 180.0

	sin75 := math.Sin(t * math.Pi)

	maxLine := squareLine / sin75

	if triangleLine <= maxLine {
		fmt.Println("possible...")
		fmt.Println("给定边长的正三角形可以放在正方形内")
		return
	}

	fmt.Println("impossible!!!")
	fmt.Println("给定边长的正三角形不可以放在正方形内")

}
