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

// This function returns true if two given iterable data structures
// contain equivalent values, and false otherwise.
template <class Iterator>
bool Equivalent( const Iterator begin_1, const Iterator end_1,
                 const Iterator begin_2, const Iterator end_2 );

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

// This function returns true if two given iterable data structures
// contain equivalent values, and false otherwise.
template <class Iterator>
bool Equivalent( const Iterator begin_1, const Iterator end_1,
                 const Iterator begin_2, const Iterator end_2 )
{
  Iterator i_1 = begin_1;
  Iterator i_2 = begin_2;

  while( i_1 != end_1 && i_2 != end_2 )
  {
    if( *i_1 != *i_2 )
    {
      return false;
    }
    std::advance( i_1, 1 );
    std::advance( i_2, 1 );
  }

  if( i_1 != end_1 || i_2 != end_2 )  // Different lengths
  {
    return false;
  }

  return true;
}

#endif  // PRINT_DATA_STRUCTURES_HPP_
