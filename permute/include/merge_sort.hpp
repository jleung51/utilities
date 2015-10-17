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

#include <iostream>
#include <stdexcept>

// Function prototypes:

// This function recursively sorts an array from least to greatest using the
// merge sort algorithm.
// An exception is thrown if:
//   array is NULL (invalid_argument)
template <class T>
void MergeSort( T* array, unsigned int len );


// Static functions:
namespace
{

  // Only for use by MergeSortHelper().
  // This function merges two sorted arrays to create a single array (in the
  // memory spaces of the original arrays) with elements from least to greatest.
  // array1 and array2 must be in consecutive memory spaces - i.e. two sections
  // of the same array.
  template <class T>
  void MergeArrays( T* array1, unsigned int len1,
                     T* array2, unsigned int len2 );
                     
  // Only for use by MergeSort().
  // This function recursively sorts an array from least to greatest using the
  // merge sort algorithm.
  template <class T>
  void MergeSortHelper( T* array, unsigned int len );

  // Only for use by MergeSortHelper().
  // This function merges two sorted arrays to create a single array (in the
  // memory spaces of the original arrays) with elements from least to greatest.
  // array1 and array2 must be in consecutive memory spaces - i.e. two sections
  // of the same array.
  template <class T>
  void MergeArrays( T* array1, unsigned int len1,
                     T* array2, unsigned int len2 )
  {
    T* array_final = array1;
    unsigned int len_final = len1 + len2;
    T array_copy[len_final];

    unsigned int i = 0;
    while( len1 > 0 && len2 > 0 )
    {
      if( array1[0] < array2[0] )  // Insert element from array1 into array_copy
      {
        array_copy[i] = array1[0];
        array1++;
        len1--;
      }
      else  // Insert element from array2 into array_copy
      {
        array_copy[i] = array2[0];
        array2++;
        len2--;
      }

      ++i;
    }

    // Leftover elements
    for( unsigned int j = 0; j < len1; ++j )
    {
      array_copy[i + j] = array1[j];
    }
    for( unsigned int j = 0; j < len2; ++j )

    {
      array_copy[i + j] = array2[j];
    }

    for( unsigned int j = 0; j < len_final; ++j )
    {
      array_final[j] = array_copy[j];
    }

    return;
  }
  
  // Only for use by MergeSort().
  // This function recursively sorts an array from least to greatest using the
  // merge sort algorithm.
  template <class T>
  void MergeSortHelper( T* array, unsigned int len )
  {
    unsigned int mid = len / 2;

    MergeSort( array,     mid );
    MergeSort( array+mid, len-mid );

    MergeArrays( array, mid, array+mid, len-mid );
    
    return;
  }
  
}

// Functions:

// This function recursively sorts an array from least to greatest using the
// merge sort algorithm.
// An exception is thrown if:
//   array is NULL (invalid_argument)
template <class T>
void MergeSort( T* array, unsigned int len )
{
  if( array == NULL )
  {
    throw std::invalid_argument( "Error: MergeSort() was given a NULL array." );
  }
  
  MergeSortHelper( array, len );
  return;
}
