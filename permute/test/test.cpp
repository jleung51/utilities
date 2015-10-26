/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-10-25
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
  for( unsigned int i = 0; i < permutations1.size(); ++i )
  {
    std::cout << permutations1[i]
              << std::endl;
  }
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
  for( unsigned int i = 0; i < permutations2.size(); ++i )
  {
    std::cout << permutations2[i]
              << std::endl;
  }
  std::cout << std::endl;
  
  return 0;
}
