/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-10-30
 *
 * This C++ header file contains functions which can be used to print
 * the contents of an array or vector.
 *
 */

#include <iostream>
#include <vector>

// Function prototypes:

// This function prints the contents of a given array in a horizontal list,
// surrounded by square brackets [].
template <class T>
void PrintArrayHorizontal( T* arr, unsigned int len );

// This function prints the contents of a given vector in a horizontal list,
// surrounded by square brackets [].
template <class T>
void PrintVectorHorizontal( std::vector<T> v );


// Function implementations::

// This function prints the contents of a given array in a horizontal list,
// surrounded by square brackets [].
template <class T>
void PrintArrayHorizontal( T* arr, unsigned int len )
{
  std::cout << "[ ";
  for( unsigned int i = 0; i < len; ++i )
  {
    std::cout << arr[i] << " ";
  }
  std::cout << "]";
  
  return;
}

// This function prints the contents of a given vector in a horizontal list,
// surrounded by square brackets [].
template <class T>
void PrintVectorHorizontal( std::vector<T> v )
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
