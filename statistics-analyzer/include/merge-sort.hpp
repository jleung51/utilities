/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-11-14
 *
 * This C++ program contains the implementation of a recursive merge sort
 * algorithm on an iterable data structure.
 *
 * Originally from the repository:
 *   https://github.com/jleung51/algorithms - sorts/other-languages/cpp
 *
 */

#pragma once

#include <iostream>
#include <iterator>
#include <stdexcept>

// Function prototypes:

// This function recursively sorts an iterable data structure from least
// to greatest using the merge sort algorithm.
template <class T, class Iterator>
void MergeSort( const Iterator begin, const Iterator end );


// Local functions:
namespace
{

// Only for use by MergeSort().
// This local function merges two consecutive sorted data structures to create a
// 'single' object with elements from least to greatest.
// Iterator end_1 is equivalent to begin_2.
template <class T, class Iterator>
void Merge( const Iterator begin_1,
            const Iterator end_1,
            const Iterator end_2 );

// Only for use by MergeSort().
// This local function merges two consecutive sorted data structures to create a
// 'single' object with elements from least to greatest.
// Iterator end_1 is equivalent to begin_2.
template <class T, class Iterator>
void Merge( const Iterator begin_1,
            const Iterator end_1,
            const Iterator end_2 )
{
  // Sorting elements into a temporary data structure up until either all of
  // the elements of one data structure has been moved:

  std::vector<T> v_temp;

  Iterator index_1 = begin_1;
  Iterator index_2 = end_1;

  while( index_1 != end_1 &&
         index_2 != end_2 )
  {
    if( *index_1 < *index_2 )
    {
      v_temp.insert( v_temp.end(), *index_1 );
      std::advance( index_1, 1 );
    }
    else
    {
      v_temp.insert( v_temp.end(), *index_2 );
      std::advance( index_2, 1 );
    }
  }

  // Moving all elements which have not yet been moved into the temporary
  // vector:

  while( index_1 != end_1 )
  {
    v_temp.insert( v_temp.end(), *index_1 );
    std::advance( index_1, 1 );
  }
  while( index_2 != end_2 )
  {
    v_temp.insert( v_temp.end(), *index_2 );
    std::advance( index_2, 1 );
  }

  // Moving sorted vector into the consecutive data structures:

  unsigned long i = 0;
  for( index_1 = begin_1; index_1 != end_1; std::advance(index_1, 1) )
  {
    *index_1 = v_temp[i];
    ++i;
  }

  for( index_2 = end_1; index_2 != end_2; std::advance(index_2, 1) )
  {
    *index_2 = v_temp[i];
    ++i;
  }

  return;
}

}  // Namespace for local functions


// Functions:

// This function recursively sorts an iterable data structure from least
// to greatest using the merge sort algorithm.
template <class T, class Iterator>
void MergeSort( const Iterator begin, const Iterator end )
{
  unsigned long size = std::distance(begin, end);
  if( size < 2 )
  {
    return;
  }

  unsigned long mid = size / 2;

  MergeSort<T>( begin, begin+mid );
  MergeSort<T>( begin+mid, end );

  Merge<T>( begin, begin+mid, end );
  return;
}
