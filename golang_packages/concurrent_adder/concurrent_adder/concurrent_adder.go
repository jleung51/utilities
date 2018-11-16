package concurrent_adder

type F_int func(int) int

// This function transforms the array values and outputs the sums.
// For a given transforms[i], the transformation is applied to each
// value and the resulting values are summed and sent to outs[i].
// Therefore, there must be the same amount of transformations and channels.
func ConcurrentAdder(arr []int, transforms []F_int, outs []chan int) {
	if len(transforms) != len(outs) {
		panic("Number of transformations must match the number of channels.")
	}

	sums := make([]int, len(outs))

	for _, v := range arr {
		for i := range transforms {
			sums[i] += transforms[i](v)
		}
	}

	for i := range outs {
		outs[i] <- sums[i]
	}
}
