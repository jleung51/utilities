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
  std::string possibilities = "aabc";
  std::vector<std::string>* permutations = Permute( possibilities );

  std::cout << "Permutations of the characters 'aabc':"
            << std::endl;
            
  for( unsigned int i = 0; i < permutations->size(); ++i )
  {
    std::cout << permutations->at(i)
              << std::endl;
  }
  
  delete permutations;
  return 0;
}
