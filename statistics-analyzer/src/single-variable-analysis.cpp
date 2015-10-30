/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-10-29
 *
 * This C++ file contains functions which analyze a single dataset,
 * a vector of values.
 *
 */

#include <cmath>
#include <iostream>
#include <stdexcept>

#include "../include/single-variable-analysis.hpp"

namespace  // Only available within this file
{

// This private function returns true if a given dataset is sorted in
// ascending order, and false otherwise.
template <class T>
bool IsSorted( std::vector<T> dataset );

}  // Unnamed namespace
