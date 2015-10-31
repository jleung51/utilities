/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-10-30
 *
 * This C++ program contains the implementation of a recursive merge sort
 * algorithm on a vector.
 *
 */

#pragma once

#include <iostream>
#include <stdexcept>
#include <vector>

// Function prototypes:

// This function recursively sorts a vector from least to greatest using the
// merge sort algorithm.
template <class T>
void MergeSortVector( std::vector<T>& v );


// Static functions:
namespace
{

// Only for use by MergeSortVectorHelper().
// This function merges two sorted vectors (arranged as consecutive elements
// in a single, larger vector) to create a "single" vector with elements from
// least to greatest.
template <class T>
void MergeVectors( const typename std::vector<T>::iterator v1_start,
                   const typename std::vector<T>::iterator v1_end,
                   const typename std::vector<T>::iterator v2_end );

// Only for use by MergeSortVector().
// This function recursively sorts a vector from least to greatest using the
// merge sort algorithm.
template <class T>
void MergeSortVectorHelper( std::vector<T>& v,
                            const typename std::vector<T>::iterator start,
                            const typename std::vector<T>::iterator end );

// Only for use by MergeSortVectorHelper().
// This function merges two sorted vectors (arranged as consecutive elements
// in a single, larger vector) to create a "single" vector with elements from
// least to greatest.
template <class T>
void MergeVectors( const typename std::vector<T>::iterator v1_start,
                   const typename std::vector<T>::iterator v1_end,
                   const typename std::vector<T>::iterator v2_end )
{
  // Sorting elements into a temporary vector up until either all of v1 or
  // v2's elements have been moved:

  std::vector<T> v_temp;
  
  typename std::vector<T>::iterator v1_index = v1_start;
  typename std::vector<T>::iterator v2_index = v1_end;
  
  while( v1_index < v1_end &&
         v2_index < v2_end )
  {
    if( *v1_index < *v2_index )
    {
      v_temp.insert( v_temp.end(), *v1_index );
      ++v1_index;
    }
    else
    {
      v_temp.insert( v_temp.end(), *v2_index );
      ++v2_index;
    }
  }
  
  // Moving all elements which have not been moved yet into the temporary
  // vector:
  
  while( v1_index < v1_end )
  {
    v_temp.insert( v_temp.end(), *v1_index );
    ++v1_index;
  }
  while( v2_index < v2_end )
  {
    v_temp.insert( v_temp.end(), *v2_index );
    ++v2_index;
  }
  
  // Moving sorted vector into v1 and v2:
  
  unsigned int i = 0;
  
  for( v1_index = v1_start; v1_index < v1_end; ++v1_index, ++i )
  {
    *v1_index = v_temp[i];
  }
  
  for( v2_index = v1_end; v2_index < v2_end; ++v2_index, ++i )
  {
    *v2_index = v_temp[i];
  }

  return;
}

// Only for use by MergeSortVector().
// This function recursively sorts a vector from least to greatest using the
// merge sort algorithm.
template <class T>
void MergeSortVectorHelper( std::vector<T>& v,
                            const typename std::vector<T>::iterator start,
                            const typename std::vector<T>::iterator end )
{
  unsigned int size = std::distance(start, end);
  if( size < 2 )
  {
    return;
  }
  
  unsigned int mid = size / 2;
  
  MergeSortVectorHelper( v, start, start+mid );
  MergeSortVectorHelper( v, start+mid, end );
  
  MergeVectors<T>( start, start+mid, end );
  
  return;
}

}  // Namespace for private functions


// Functions:

// This function recursively sorts a vector from least to greatest using the
// merge sort algorithm.
template <class T>
void MergeSortVector( std::vector<T>& v )
{
  MergeSortVectorHelper( v, v.begin(), v.end() );
}
