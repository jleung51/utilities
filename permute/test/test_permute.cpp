/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-10-30
 *
 * This C++ file tests the implementation of the permutation function in
 * permute.cpp.
 *
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "../include/merge_sort_vector.hpp"
#include "../include/permute.hpp"

// Static functions:
namespace
{

// This static function prints the contents of a given vector in a
// vertical list.
template <class T>
void PrintVectorVertical( std::vector<T> v );

// This static function prints the contents of a given vector in a
// vertical list.
template <class T>
void PrintVectorVertical( std::vector<T> v )
{
  for( unsigned int i = 0; i < v.size(); ++i )
  {
    std::cout << v[i]
              << std::endl;
  }
  
  return;
}
  
}  // Unnamed namespace for static functions

int main()
{
  std::cout << std::endl
            << "TESTING PERMUTE():"
            << std::endl
            << "______________________________________________"
            << std::endl
            << std::endl;

  std::string possibilities1 = "aabc";
  std::vector<std::string> permutations1;
  
  try
  {
    Permute( permutations1, possibilities1, false );
  }
  catch( std::exception& e )
  {
    std::cout << e.what()
              << std::endl;
  }

  std::cout << "Permutations of the characters '"
            << possibilities1
            << "':"
            << std::endl;
  PrintVectorVertical( permutations1 );
  std::cout << std::endl;
  
  std::string possibilities2 = "abc";
  std::vector<std::string> permutations2;
  
  try
  {
    Permute( permutations2, possibilities2, true );
  }
  catch( std::exception& e )
  {
    std::cout << e.what()
              << std::endl;
  }
  
  std::cout << "Subsequence permutations of the characters '"
            << possibilities2
            << "':"
            << std::endl;
  PrintVectorVertical( permutations2 );
  std::cout << std::endl;
  
  return 0;
}
