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

int main()
{
  std::vector<int> v;
  for( unsigned int i = 0; i < 10; ++i )
  {
    v.push_back( 10-i );
  }
  
  std::cout << "The contents of the vector before sorting are ";
  PrintVector( v );
  std::cout << std::endl;
  
  MergeSortVector( v );
  
  std::cout << "The contents of the vector after sorting are  ";
  PrintVector( v );
  std::cout << std::endl;

  return 0;
}
