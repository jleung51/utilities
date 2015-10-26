/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-10-17
 *
 * This C++ file tests the implementation of the permumutation function in
 * permute.cpp.
 *
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

#include "../include/permute.hpp"

// Static functions:
namespace
{

// This static function prints the contents of a given array in order.
template <class T>
void PrintArray( T* array, unsigned int len );

// This static function prints the contents of a given array in order.
template <class T>
void PrintArray( T* array, unsigned int len )
{

  for( unsigned int i = 0; i < len; ++i )
  {
    std::cout << array[i];
    
    if( i != len-1 )
    {
      std::cout << " ";
    }
  }
  
  return;
}
  
}  // Unnamed namespace

int main()
{
  std::cout << std::endl
            << "TESTING PERMUTE():"
            << std::endl
            << "______________________________________________"
            << std::endl
            << std::endl;

  std::string possibilities1 = "aabc";
  std::vector<std::string>* permutations1 = Permute( possibilities1, false );

  std::cout << "Permutations of the characters 'aabc':"
            << std::endl;
            
  for( unsigned int i = 0; i < permutations1->size(); ++i )
  {
    std::cout << permutations1->at(i)
              << std::endl;
  }
  std::cout << std::endl;
  delete permutations1;
  
  std::string possibilities2 = "abc";
  std::vector<std::string>* permutations2 = Permute( possibilities2, true );
  std::cout << "Subsequence permutations of the characters 'abc':"
            << std::endl;
            
  for( unsigned int i = 0; i < permutations2->size(); ++i )
  {
    std::cout << permutations2->at(i)
              << std::endl;
  }
  std::cout << std::endl;
  delete permutations2;
  
  return 0;
}
