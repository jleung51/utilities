package main

import (
	"../concurrent_adder"
	"fmt"
	"math"
)

// This function runs the concurrent adder function to calculate the sum,
// sum of squares, and sum of square roots of the given array, parallel
// with the given number of chunks.
func sumSquareSumSquareRtSum(arr []int, chunks int) (sum, squareSum, squareRtSum int) {

	length := len(arr)
	if length%chunks != 0 {
		panic("Chunks must divide slice size without remainder.")
	}

	fSum := func(x int) int { return x }
	fSquareSum := func(x int) int { return x * x }
	fSquareRtSum := func(x int) int { return int(math.Sqrt(float64(x))) }
	transforms := [](concurrent_adder.F_int){fSum, fSquareSum, fSquareRtSum}

	chans := [](chan int){
		make(chan int),
		make(chan int),
		make(chan int)}

	chunkLength := length / chunks
	for i := 0; i < chunks; i++ {
		go concurrent_adder.ConcurrentAdder(
			arr[chunkLength*i:chunkLength*(i+1)],
			transforms, chans)
	}

	sum, squareSum, squareRtSum = 0, 0, 0
	for i := 0; i < chunks; i++ {
		sum += <-chans[0]
		squareSum += <-chans[1]
		squareRtSum += <-chans[2]
	}

	return sum, squareSum, squareRtSum
}

func main() {
	arr_int := []int{1, 3, 6, 2, 5, 8, 1, 4, 9, 5, 8, 2}
	sum, squareSum, squareRtSum := sumSquareSumSquareRtSum(arr_int, 4)
	fmt.Println("Array:", arr_int)
	fmt.Println("  Sum:", sum)
	fmt.Println("  Sum of squares:", squareSum)
	fmt.Println("  Sum of square roots:", squareRtSum)

	arr_int = []int{0, 0}
	sum, squareSum, squareRtSum = sumSquareSumSquareRtSum(arr_int, 2)
	fmt.Println("Array:", arr_int)
	fmt.Println("  Sum:", sum)
	fmt.Println("  Sum of squares:", squareSum)
	fmt.Println("  Sum of square roots:", squareRtSum)

	arr_int = []int{-1, 1}
	sum, squareSum, squareRtSum = sumSquareSumSquareRtSum(arr_int, 2)
	fmt.Println("Array:", arr_int)
	fmt.Println("  Sum:", sum)
	fmt.Println("  Sum of squares:", squareSum)
	fmt.Println("  Sum of square roots:", squareRtSum)
}
