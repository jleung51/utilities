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

//TODO TESTING ONLY; REMOVE ONCE IMMEDIATE TESTING IS COMPLETE
// This function prints the contents of a given vector.
template <class T>
void PrintVector( std::vector<T> v )
{
  std::cout << "[ ";
  
  unsigned int i = 0;
  typename std::vector<T>::iterator v_index;
  for( v_index = v.begin(); v_index < v.end(); ++v_index, ++i )
  {
    std::cout << v.at( i ) << " ";
  }
  
  std::cout << "]";

  return;
}


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
void MergeVectors( std::vector<T>& v,
                   typename std::vector<T>::iterator v1_start,
                   typename std::vector<T>::iterator v1_end,
                   typename std::vector<T>::iterator v2_end );

// Only for use by MergeSortVectorHelper().
// This function merges two sorted vectors (arranged as consecutive elements
// in a single, larger vector) to create a "single" vector with elements from
// least to greatest.
template <class T>
void MergeVectors( std::vector<T>& v,
                   typename std::vector<T>::iterator v1_start,
                   typename std::vector<T>::iterator v1_end,
                   typename std::vector<T>::iterator v2_end )
{
  /* // Code to merge two vectors (non-functional)
  std::vector<T> v_temp;
  
  typename std::vector<T>::iterator v1_index = v1.begin();
  typename std::vector<T>::iterator v2_index = v2.begin();
  
  unsigned int i_1 = 0;
  unsigned int i_2 = 0;
  
  while( v1_index < v1.end() &&
         v2_index < v2.end() )
  {
    if( v1[i_1] < v2[i_2] )
    {
      v_temp.insert( v_temp.end(), v1[i_1] );
      ++v1_index;
      ++i_1;
    }
    else
    {
      v_temp.insert( v_temp.end(), v2[i_2] );
      ++v2_index;
      ++i_2;
    }
  }
  
  while( i_1 < v1.size() )
  {
    v_temp.insert( v_temp.end(), v1[i_1] );
    ++i_1;
  }
  while( i_2 < v2.size() )
  {
    v_temp.insert( v_temp.end(), v2[i_2] );
    ++i_2;
  }
  
  std::cout << "Sorted array ";
  PrintVector( v_temp );
  std::cout << " was created from the arrays ";
  PrintVector( v1 );
  PrintVector( v2 );
  std::cout << std::endl;
  
  typename std::vector<T>::iterator v_index;
  
  for( unsigned int j = 0; j < v1.size(); ++j )
  {
    v1[j] = v_temp[j];
  }
  
  for( unsigned int k = 0; k < v2.size(); ++k )
  {
    v2[k] = v_temp[ v1.size() + k ];
  }
  
  std::cout << "Final array: ";
  PrintVector( v1 );
  PrintVector( v2 );
  std::cout << std::endl << std::endl;
*/

/* // Code to merge templated arrays
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
*/
  return;
}

// Only for use by MergeSortVector().
// This function recursively sorts a vector from least to greatest using the
// merge sort algorithm.
template <class T>
void MergeSortVectorHelper( std::vector<T>& v,
                            typename std::vector<T>::iterator start,
                            typename std::vector<T>::iterator end )
{
  unsigned int size = std::distance(start, end);
  if( size < 2 )
  {
    return;
  }
  
  unsigned int mid = size / 2;
  
  MergeSortVectorHelper( v, start, start+mid );
  MergeSortVectorHelper( v, start+mid, end );
  
  //MergeVectors( v1, v2 );
  
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
