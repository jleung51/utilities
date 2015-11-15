/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-11-14
 *
 * This C++ file tests the implementation of the C++ sort functions against
 * the STL sort implementation.
 *
 * Originally from the repository:
 *   https://github.com/jleung51/algorithms - sorts/other-languages/cpp
 *
 */

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>

#include "../include/merge-sort.hpp"

// Local functions:
namespace
{

// This local function prints the contents of a given iterable data
// structure in a horizontal list, surrounded by brackets [].
template <class Iterator>
void PrintHorizontal( const Iterator begin, const Iterator end );

// This local function returns true if two given iterable data structures
// contain equivalent values, and false otherwise.
template <class Iterator>
bool Equivalent( const Iterator begin_1, const Iterator end_1,
                 const Iterator begin_2, const Iterator end_2 );

// This local function prints the contents of a given iterable data
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

// This local function returns true if two given iterable data structures
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

}  // Unnamed namespace for local functions

int main()
{
  srand(time(0));  // Seeding random number generator
  std::vector<int> v_unsorted;
  for( unsigned int i = 0; i < 10; ++i )
  {
    v_unsorted.push_back( rand() % 100 );
  }

  std::vector<int> v_sorted( v_unsorted.begin(), v_unsorted.end() );
  MergeSort<int>( v_sorted.begin(), v_sorted.end() );

  std::vector<int> v_sorted_correct( v_unsorted.begin(), v_unsorted.end() );
  std::sort( v_sorted_correct.begin(), v_sorted_correct.end() );

  std::cout << std::endl
            << "TESTING MERGESORT():"
            << std::endl
            << "______________________________________________"
            << std::endl
            << std::endl;

  std::cout << "The contents of the vector before sorting are ";
  PrintHorizontal( v_unsorted.begin(), v_unsorted.end() );
  std::cout << std::endl;

  std::cout << "The contents of the vector after sorting are  ";
  PrintHorizontal( v_sorted.begin(), v_sorted.end() );
  std::cout << std::endl;

  bool sorted_correctly = Equivalent( v_sorted.begin(),
                                      v_sorted.end(),
                                      v_sorted_correct.begin(),
                                      v_sorted_correct.end() );
  if( sorted_correctly )
  {
    std::cout << "The vector was successfully sorted." << std::endl;
  }
  else
  {
    std::cout << "The vector was not successfuly sorted; the correct "
      << "vector should be ";
    PrintHorizontal( v_sorted_correct.begin(), v_sorted_correct.end() );
    std::cout << "." << std::endl;
  }

  std::cout << std::endl;
  return 0;
}
