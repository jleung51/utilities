# Concurrent Adder

This Golang package provides a function to generate a sum of an integer array (with each value transformed first) and send it through a channel (to allow for concurrency). The number of transformations and channels is variable.

This is the rough equivalent of a set of `MapReduce` functions, with the `map` being a function reference as an argument and the `reduce` being the sum of the result of the function applied to the value.

This is a terrible thing and I was inspired by [@CtrlShiftGo](https://github.com/ctrlshiftgo) and [@GalaxyVintage](https://github.com/galaxyvintage) to do it.