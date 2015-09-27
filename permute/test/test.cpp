/*
 *
 * Author: Jeffrey Leung
 * Last edited: 2015-09-27
 *
 * This C++ file tests the implementation of the permumutation function in
 * permute.cpp.
 *
 */

#include <iostream>
#include <string>
#include <vector>

#include "../include/permute.hpp"

int main()
{
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
