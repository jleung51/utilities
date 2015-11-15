/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-11-14
 *
 * This C++ header file contains a function to print the contents of an
 * iterable data structure.
 *
 */

#ifndef PRINT_DATA_STRUCTURES_HPP_
#define PRINT_DATA_STRUCTURES_HPP_

#include <iostream>
#include <iterator>

// Function prototypes:

// This function prints the contents of a given iterable data
// structure in a horizontal list, surrounded by brackets [].
template <class Iterator>
void PrintHorizontal( const Iterator begin, const Iterator end );

// Function implementations:

// This function prints the contents of a given iterable data
// structure in a horizontal list, surrounded by brackets [].
template <class Iterator>
void PrintHorizontal( const Iterator begin, const Iterator end )
{
  std::cout << "[ ";
  unsigned int i = 0;
  for( Iterator index = begin; index != end; std::advance(index, 1) )
  {
    std::cout << *index << " ";
    ++i;
  }
  std::cout << "]";
  return;
}

#endif  // PRINT_DATA_STRUCTURES_HPP_
