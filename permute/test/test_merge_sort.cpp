/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-10-30
 *
 * This C++ file tests the implementation of the merge sort (vector) function
 * in merge_sort_vector.hpp.
 *
 */

#include <iostream>
#include <vector>

#include "../include/merge_sort_vector.hpp"

// Static functions:
namespace
{

// This static function prints the contents of a given vector in a
// horizontal list, surrounded by brackets [].
template <class T>
void PrintVectorHorizontal( std::vector<T> v );

// This static function prints the contents of a given vector in a
// horizontal list, surrounded by brackets [].
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

}  // Unnamed namespace for static functions

int main()
{
  std::cout << std::endl
            << "TESTING MERGESORTVECTOR():"
            << std::endl
            << "______________________________________________"
            << std::endl
            << std::endl;

  std::vector<int> v;
  for( unsigned int i = 0; i < 10; ++i )
  {
    v.push_back( 10-i );
  }
  
  std::cout << "The contents of the vector before sorting are ";
  PrintVectorHorizontal( v );
  std::cout << std::endl;
  
  MergeSortVector( v );
  
  std::cout << "The contents of the vector after sorting are  ";
  PrintVectorHorizontal( v );
  std::cout << std::endl;

  std::cout << std::endl;
  return 0;
}
