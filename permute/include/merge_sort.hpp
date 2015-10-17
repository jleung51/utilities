/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-10-17
 * Forked from https:github.com/jleung51/algorithms
 *
 * This C++ program contains the implementation of a recursive merge sort
 * algorithm on an array of integers.
 *
 */

#pragma once

// This function recursively sorts an array from least to greatest using the
// merge sort algorithm.
template <class T>
void MergeSort( T* array, unsigned int len );

#endif
