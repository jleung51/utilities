/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-10-30
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

// Function prototypes:

// This private function returns true if a given vector dataset is sorted in
// ascending order, and false otherwise.
template <class T>
bool IsSorted( std::vector<T>& dataset );

// Function implementations:

// This private function returns true if a given vector dataset is sorted in
// ascending order, and false otherwise.
template <class T>
bool IsSorted( std::vector<T>& dataset )
{
  for( unsigned int i = 0; i < dataset.size()-1; ++i )
  {
    if( dataset[i] > dataset[i+1] )
    {
      return false;
    }
  }
  return true;
}

}  // Unnamed namespace
